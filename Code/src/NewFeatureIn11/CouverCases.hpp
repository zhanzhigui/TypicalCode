#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>

using namespace std;

const string  ORIGIN        = "origin=";
const string  HEADING       = "heading=";
const string  SPEED_IN_MPS  = "speed_in_mps=";
const string  DEST          = "destination=";
void ConvertCases()
{
    ifstream input("F:\\Data\\RMU\\Regressionex_new_new\\Regressionex\\data\\testsuites\\US_CA_Routing.xml", ios::in);
    if( !input )
    {
        cerr << "Open input file error!" << endl;
        exit( -1 );
    }
    ofstream output( "F:\\Data\\RMU\\Regressionex_new_new\\Regressionex\\data\\testsuites\\US_CA_Routing_new.xml", ios::out);
    if( !output )
    {
        cerr << "Open output file error!" << endl;
        exit( -1 );
    }

    stringstream ostr ;

/*
    ostr << "<?xml version=\"1.0\" encoding=\"UTF-8\"?> \n"
        << "<testSuite \n"
        << "\t" << "name=\"TestGuidanceNA\" \n"
        << "\t" <<  "javaClass=\"com.telenav.navstar.proxy.regressionex.TestRoute\" \n"
        << "\t" <<  "description=\"tests route composition functions of nav star\" \n"
        << "\t" <<  "smartComparison=\"true\" \n"
        << "\t" <<  "env=\"win32_data_path=F:\\DATA\\RMU\\USA-OSM-18M05-RMUROUTING-20180522-201136\\;win32_config_path=F:\\DATA\\RMU\\USA-OSM-18M05-RMUROUTING-20180522-201136\\config\\;turnStyle=server;useHTF=false\">\" + \n";
*/
    int count = 1;
    while(!input.eof())
    {
        char buffer[2048];
        input.getline(buffer, 2048);
        string str(buffer);
        
        if(string::npos != str.find("param")
            && string::npos == str.find("<!--"))
        {
            size_t origin_start = str.find(ORIGIN) + ORIGIN.size();
            size_t origin_end = str.find_first_of(";", origin_start);
            string orig(str.substr(origin_start, origin_end-origin_start));

            size_t heading_start = str.find(HEADING) + HEADING.size();
            size_t heading_end = str.find_first_of(";" , heading_start);
            string heading("-1");
            if (string::npos != str.find(HEADING)
                && (heading_end - heading_start > 0) )
            {
                heading = str.substr(heading_start, heading_end - heading_start);
            }

            size_t speed_start = str.find(SPEED_IN_MPS) + SPEED_IN_MPS.size();
            size_t speed_end = str.find_first_of(";" , speed_start);
            string speed("0");
            if (string::npos != str.find(SPEED_IN_MPS)
                && (speed_end - speed_start > 0) )
            {
                speed = str.substr(speed_start, speed_end - speed_start);
            }

            size_t dest_start = str.find(DEST) + DEST.size();
            size_t dest_end = str.find_first_of(";" , dest_start);
            string dest = str.substr(dest_start, dest_end - dest_start);

            ostr << "\t\t" << "<param name=\"orig\" type=\"java.lang.String\" value=\""
                << orig << "\"/> \n"
                << "\t\t" << "<param name=\"dest\" type=\"java.lang.String\" value=\""
                << dest << "\"/> \n" 
                << "\t\t" << "<param name=\"nRouteSpeed\" type=\"long\" value=\""
                << speed << "\"/> \n"
                << "\t\t" << "<param name=\"dOriginHeading\" type=\"long\" value=\""
                << heading << "\"/> \n";
        }
        else
        {
            ostr << str << "\n";  
            if (std::string::npos != str.find("<testCase"))
            {
                ostr << "\t\t" << "<param name=\"ServerUrl\" type=\"java.lang.String\" value=\"http://ec2s-waikikirmu-01.stg.mypna.com:8080/more/directions/v4/json?\"/>\n";
            }
                       
        }
        cout << count++ << endl;
    }

    output << ostr.str();
    input.close();
    output.close();
}

class TestConvertCases
{
public:
    TestConvertCases()
    {
        cout<<"******* TestConvertCases BEGIN *******"<<endl;
        ConvertCases();
        cout<<"******* TestConvertCases END *******"<<endl;
    }
};