Windows:
	make builds & cd builds
	cmake -G "NMake Makefiles" -DCMAKE_INSTALL_PREFIX=../bin ..
	nmake install
	
Linux/cygwin
	make builds & cd builds
	cmake -G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX=../bin ..
	nmake install
