export PATH="$PATH:$HOME/bin"
PORT=8080 MODE=docker bazel run //src:server \
		--incompatible_depset_is_not_iterable=false \
    	--jobs 8