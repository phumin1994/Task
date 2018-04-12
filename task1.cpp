#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp>

class CSVReader
{
    std::string fileName;
    std::string delimeter;
    
public:
    CSVReader(std::string filename, std::string delm = ",") :
        fileName(filename), delimeter(delm)
    { }
    
    std::vector<std::vector<std::string> > getData();
};

std::vector<std::vector<std::string> > CSVReader::getData()
{
    std::ifstream file(fileName);
    std::vector<std::vector<std::string> > dataList;
    std::string line = "";
    
    while (getline(file, line))
    {
        std::vector<std::string> vec;
        boost::algorithm::split(vec, line, boost::is_any_of(delimeter));
    }
    file.close();
    
    return dataList;
}

int main()
{
    CsvReader reader("SacramentocrimeJanuary2006.csv");
    std::vector<std::vector<std::string> > dataList = reader.getData();
    for(std::vector<std::string> vec : dataList)
    {
        for(std::string data : vec)
        {
            std::cout<<data << " , ";
        }
        std::cout<<std::endl;
    }

    return 0;
}