#include <iostream>
#include <string>
#include <fstream>


std::string replace(std::string &line, std::string &s1, std::string &s2)
{
    std::size_t pos = 0;
    std::size_t found;
    std::string rep_line;
    while ((found = line.find(s1, pos)) != std::string::npos)
    {
        rep_line += line.substr(pos, found - pos);
        rep_line += s2;
        pos = found + s1.length();
    }
    rep_line += line.substr(pos);
    return (rep_line);
}

int main(int ac, char **av)
{
    if (ac != 4)
        return (1);
    std::string file(av[1]);
    std::string s1(av[2]);
    std::string s2(av[3]);
    std::ifstream infile(file.c_str());
    if (!infile)
    {
        std::cerr << "Error: Cannot open file " << file << std::endl;
        return 1;
    }
    std::ofstream outfile((file + ".replace").c_str());
    std::string line;
    while (getline(infile, line))
        outfile << replace(line, s1, s2) << std::endl;
    infile.close();
    outfile.close();
    return (0);
}