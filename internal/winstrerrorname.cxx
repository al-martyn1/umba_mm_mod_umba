#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

using std::cout;
using std::cerr;
using std::cin;

int main(int argc, char* argv[])
{
    bool bFirst = true;

    cout << "#pragma once\n\n\n";
    cout << "#include <string>\n";
    cout << "#include <unordered_map>\n";
    cout << "\n\n\n";
    cout << "namespace umba{\n";
    cout << "namespace win32{\n";
    cout << "\n\n\n";

    cout << "inline\nstd::unordered_map<unsigned, const char*> makeStrErrorNameMap()\n";
    cout << "{\n";
    cout << "    return std::unordered_map<unsigned, const char*>\n";
    cout << "        {\n";
    cout << "        { ";

    std::string str;
    while(std::getline(cin, str))
    {
        cerr << "Line: " << str;
        if (str.empty() || str[0]!='#')
        {
            cerr << ", skip it\n";
            continue;
        }
        cerr << "\n";

        std::istringstream iss = std::istringstream(str);

        std::string defineStr;
        std::string nameStr  ;
        std::string codeStr  ;

        iss >> defineStr;
        iss >> nameStr  ;
        iss >> codeStr  ;

        cerr << "    defineStr: " << defineStr << "\n";
        cerr << "    nameStr  : " << nameStr   << "\n";
        cerr << "    codeStr  : " << codeStr   << "\n";

        if (defineStr!="#define")
            continue;

        if (nameStr.empty() || codeStr.empty())
            continue;

        if (codeStr[codeStr.size()-1]=='l' || codeStr[codeStr.size()-1]=='L')
        {
            codeStr.erase(codeStr.size()-1, 1);
        }

        if (codeStr.empty())
            continue;

        unsigned code = (unsigned)-1;
        try
        {
            long lCode = std::atol(codeStr.c_str());
            if (lCode>=0)
                code = (unsigned)lCode;
        }
        catch(...)
        {
        }

        if (code==(unsigned)-1)
            continue;

        if (!bFirst)
            cout << "        , ";

        bFirst = false;

        cout << "{ " << code << ", " << "\"" << nameStr << "\"" << " }\n";

    }

    cout << "        }\n";
    cout << "        };\n";
    cout << "}\n\n";

    cout << "inline\n";
    cout << "const std::unordered_map<unsigned, const char*>& getStrErrorNameMap()\n";
    cout << "{\n";
    cout << "    static auto m = makeStrErrorNameMap();\n";
    cout << "    return m;\n";
    cout << "}\n";


    cout << "\n\n\n";
    cout << "} // namespace win32\n";
    cout << "} // namespace umba\n";
    cout << "\n\n";

    return 0;
}
