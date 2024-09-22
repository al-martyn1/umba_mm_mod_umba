call cxx winstrerrorname.cxx
if exist winstrerrorname.exe winstrerrorname.exe < winerror_prepared.h > winstrerrorname.h 2>winstrerrorname.log
if exist winstrerrorname.exe del winstrerrorname.exe
if exist winstrerrorname.obj del winstrerrorname.obj
