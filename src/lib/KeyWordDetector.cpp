#include "KeyWordDetector.hpp"

#include <vector>
#include <string>
#include <algorithm>

const int dawn::KeyWordDetector::numLetter;
dawn::KeyWordDetector::Vertex::Vertex(int p, char ch) : p(p), pch(ch) {
	next.assign(numLetter, -1);
	go.assign(numLetter, -1);
}

int dawn::KeyWordDetector::toInt(char ch) {
	return ch - ' ';
}

dawn::KeyWordDetector::KeyWordDetector() {
	t.emplace_back();
}

void dawn::KeyWordDetector::addString(std::string const& s, int idx) {
	int v = root;
	for (auto ch : s) {
		int c = toInt(ch);
		if (t[v].next[c] == -1) {
			t[v].next[c] = t.size();
			t.emplace_back(v, ch);
		}
		t[t[v].next[c]].p = v;
		t[t[v].next[c]].pch = ch;
		v = t[v].next[c];
	}
	t[v].leaf = true;
	t[v].patternIndex.push_back(idx);
	t[v].patternLength = s.length();
	numPattern = std::max(numPattern, idx);
}

int dawn::KeyWordDetector::getLink(int v) {
	if (t[v].link == -1) {
		if (v == 0 || t[v].p == 0)
			t[v].link = 0;
		else
			t[v].link = go(getLink(t[v].p), t[v].pch);
	}
	return t[v].link;
}

int dawn::KeyWordDetector::go(int v, char ch) {
	int c = toInt(ch);
	if (t[v].go[c] == -1) {
		if (t[v].next[c] != -1)
			t[v].go[c] = t[v].next[c];
		else
			t[v].go[c] = v == 0 ? 0 : go(getLink(v), ch);
	}
	return t[v].go[c];
} 

int dawn::KeyWordDetector::getExitLink(int v) {
	if (t[v].exitLink != -1) return t[v].exitLink;
	int k = getLink(v);
	if (k == 0 || t[k].leaf) return t[v].exitLink = k;
	return t[v].exitLink = getExitLink(k);
}

std::vector<std::vector<int> > dawn::KeyWordDetector::searchForOccurenceInString(const std::string& text) {
	std::vector<std::vector<int> > ans(numPattern, std::vector<int>());
	int idx = 1;
	int v = root;
	for (auto &ch : text) {
		v = go(v, ch);
		int k = v;
		while(k != 0) {
			if (t[k].leaf) 
				for (auto &s : t[k].patternIndex) 
					ans[s].emplace_back(idx - t[k].patternLength);
			k = getExitLink(k);
		} 
		idx++;
	}
	return ans;
}

