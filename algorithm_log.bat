set order=pat_a1092
set edit_order=_0
set input_order=_1
set inputfile=%order%_input%input_order%.txt
set fileName=%order%%edit_order%.cpp
set outputName=hello.exe
cd c:\NeedBackups\c++\algorithm_log\%order%
g++ %fileName% -o %outputName%
.\%outputName% <%inputfile%
del .\%outputName%
cmd