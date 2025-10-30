#include <iostream>
#include <fstream>

typedef std::string str;

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Requirements : [./exec] [filename] [str1] [str2]" << std::endl;
        return (1);
    }

    str     text;
    str     newFile = str(av[1]) + ".replace";

    std::ifstream   file(av[1]);
    if (!file.is_open())
    {
        std::cerr << "Error: couldn't open file '" << av[1] << "'\n";
        return (1);
    }

    std::ofstream   rep(newFile.c_str());
    if (!rep.is_open())
    {
        std::cerr << "Error: couldn't open file '" << newFile << "'\n";
        file.close();
        return (1);
    }

    str fulltext = "";

    while (std::getline(file, text)) {
        fulltext += text;
        if (!file.eof())
            fulltext += "\n";
    }

    str::size_type  pos = 0;
    str::size_type  len = str(av[2]).length();
    str             toReplace = str(av[2]);
    str             replaceWith = str(av[3]);
    while ((pos = fulltext.find(toReplace, pos)) != str::npos)
    {
        fulltext.erase(pos, len);
        fulltext.insert(pos, replaceWith);
        pos += replaceWith.length();
    }
    rep << fulltext;
    file.close();
    rep.close();
    return (0);
}