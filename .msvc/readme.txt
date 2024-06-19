visual studio macro with the path of a props file - https://stackoverflow.com/questions/10400222/visual-studio-macro-with-the-path-of-a-props-file
MSBuild Reserved and Well-Known Properties - https://learn.microsoft.com/ru-ru/previous-versions/visualstudio/visual-studio-2015/msbuild/msbuild-reserved-and-well-known-properties?view=vs-2015&redirectedfrom=MSDN
The solution is $(MSBuildThisFileDirectory)

Настраиваем удобную сборку проектов в Visual Studio - https://habr.com/ru/articles/448216/

1) Если не хочется заморачиваться с импортами своих .props и .targets файлов в каждый проект, 
   то можно создать файл Directory.Build.props и/или Directory.Build.targets, которые импортируются автоматически.