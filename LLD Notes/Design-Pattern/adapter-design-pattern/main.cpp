#include <iostream>

/*
                        |--------------------------adaptaee
//client ---> target ---|                           |
                        |-----adapter---------------|

Example
                            |--------------------------(datanalyser)
//user ---> data(json) -----|                           |
                            |-----adapter(converts xml to json)---------------|

*/

class XMLdata
{
private:
    std::string xmlData;

public:
    XMLdata(std::string xmlData)
    {
        this->xmlData = xmlData;
    }
    std::string getXMLdata()
    {
        return xmlData;
    }
};

class DataAnalyticTool
{
protected:
    std::string jsonData;

public:
    DataAnalyticTool(){};
    DataAnalyticTool(std::string jsonData)
    {
        this->jsonData = jsonData;
    }

    virtual void analyseData()
    {
        std::cout << "Analysing Data:- " << jsonData << std::endl;
    }
};

class Adapter : public DataAnalyticTool
{
private:
    std::string adaptData;

public:
    Adapter(XMLdata *xmlData)
    {
        this->adaptData = xmlData->getXMLdata();
    }

    void analyseData() override
    {
        std::cout << "converting to XML to JSON format" << std::endl;
        jsonData = "<converted JSON data>";
        DataAnalyticTool::analyseData();
    }
};

class Client
{
public:
    void processData(DataAnalyticTool *tool)
    {
        tool->analyseData();
    }
};

int main()
{
    XMLdata *xmlFormat = new XMLdata("XML data");
    DataAnalyticTool *example = new Adapter(xmlFormat);
    Client *user = new Client;
    user->processData(example);

    delete xmlFormat;
    delete example;
    delete user;

    return 0;
}