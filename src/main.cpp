#include <cpr/cpr.h>
#include <iostream>
#include <nlohmann/json.hpp>cmake
#include <fstream>
#include <ctime>
#include <algorithm>

//https://gist.github.com/lyandut/98d4eb75add96fafdc06c6f94c9317fe

using json = nlohmann::json;

void replace(std::string& s) {
    std::replace(s.begin(), s.end(), ' ', '-');
}

std::string suburb, countryCode, city, locationQuery;


int main()
{
        std::cout << "Enter Country Code (or press Enter to skip): ";
        std::getline(std::cin, countryCode);

        std::cout << "Enter City: ";
        std::getline(std::cin, city);
       
        std::cout << "Enter Suburb (or press Enter to skip): ";
        std::getline(std::cin, suburb);
        if (!suburb.empty()) {
            replace(suburb);
            locationQuery += suburb + ",";
        }
        
        if (!city.empty()) {
            replace(city);
            locationQuery += city; ;
        }
        if (!countryCode.empty()) {
            locationQuery += "," + countryCode;
        }
        cpr::Response g = cpr::Get(cpr::Url{ "http://api.openweathermap.org/geo/1.0/direct?q=" + locationQuery + "&limit=5&appid=b8a4c81366248d8a082474c9d0824693" });

        json lonlat = json::parse(g.text);
        double lon = lonlat[0]["lon"];
        double lat = lonlat[0]["lat"];

        std::string lonn = std::to_string(lon);
        std::string latt = std::to_string(lat);

        cpr::Response r = cpr::Get(cpr::Url{ "https://api.openweathermap.org/data/2.5/weather?lat=" + latt + "&lon=" + lonn + "&appid=b8a4c81366248d8a082474c9d0824693&units=metric&lang=en" });

  

        int timezone_offset = 36000;

        if (r.status_code == 200)
        {


            json j;

            j = json::parse(r.text);


            std::time_t dt = j["dt"];
            std::string country = j["sys"]["country"];
            std::string name = j["name"];
            std::string description = j["weather"][0]["description"];
            double temp = j["main"]["temp"];
            double humidity = j["main"]["humidity"];





            std::cout << "Location: " << name << ", " << country << std::endl;
            std::cout << "Weather: " << description << std::endl;
            std::cout << "Temperature: " << temp << std::endl;
            std::cout << "Humidity: " << humidity << "%" << std::endl;


        }
        else {
            std::cerr << "'iin sha' allah najid hadha alkhata";
        }

        std::cout << "Done fetching weather!" << std::endl;

        std::cout << "Press Enter to exit...";
        std::cin.get();
   

}
