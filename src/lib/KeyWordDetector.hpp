#pragma once

#ifndef KEY_WORD_DETECTOR
#define KEY_WORD_DETECTOR
/**
* AhoCorasick algorithm implementation
*/
#include <vector>
#include <string>
#include <algorithm>

namespace dawn {
	class KeyWordDetector {
	private:
		static const int numLetter = 100; // number of character
		int numPattern = 0;
		int root = 0;
		struct Vertex {
			std::vector<int> next, go, patternIndex;
			bool leaf = false;
			int p = -1;
			char pch;
			int link = -1;
			int exitLink = -1;
			int patternLength = -1;
			Vertex(int p=-1, char ch='$');
		};	
		int toInt(char ch);
	public:
		std::vector<Vertex> t;
		KeyWordDetector();
		void addString(std::string const& s, int idx=1);
		int getLink(int);
		int go(int, char);
		int getExitLink(int);
		std::vector<std::vector<int> > searchForOccurenceInString(const std::string&);
	};
}
#endif
