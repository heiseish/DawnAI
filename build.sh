export PATH="$PATH:$HOME/bin"
bazel build //src:server \
		--incompatible_depset_is_not_iterable=false \
    	--jobs 8