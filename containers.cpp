#include "containers.h"
#include "csvstream.h"
#include <iostream>
#include <algorithm>
#include <iterator>

/**
 * @brief reads in the data from the file and loads into car structure
 * @param cars
 * @param in_file
 */
void Load_Data(std::vector<Car> &cars, const std::string &in_file){
    Car temp; //new car object
    csvstream csvin(in_file); // creates object to read file in
    std::map<std::string, std::string> row; // map for car object

    //reads data in
    while(csvin >> row){
        temp.vin = row["vin"];
        temp.make = row["make"];
        temp.year = std::stoi (row["car_year"]);
        temp.color = row["car_color"];
        temp.value = std::stod(row["value"]);
        temp.state = row["state"];
        cars.push_back(temp);
    }
}

/**
 * @brief find the min or max value in the car object based on user input
 * @param cars reference to car object
 * @param operation int to hold min or max
 * @return returns a car object
 */
Car Car_Value_Analytics(std::vector<Car> &cars, int operation){

    //returns min value from car object
    if(operation == MIN) {
        auto min_value = std::min_element(cars.begin(), cars.end(),
                                          [](Car &value1, Car &value2){return value1.value < value2.value;});

        return *min_value;
    }
    //returns max value from car object
    else{
        auto max_value = std::max_element(cars.begin(), cars.end(),
                                          [](Car &value1, Car &value2){return value1.value < value2.value;});
        return *max_value;
    }
}

/**
 * @brief finds the records of the cars made in a certain decade based on user input.
 * sorts the value of those records from lowest to highest
 * @param cars reference to car object
 * @param decade user input
 * @return a vector of car objects from a specific decade
 */
std::vector<Car> Cars_from_decade(std::vector<Car> &cars, int decade){
    std::vector<Car> sorted_cars;

    int model_year = (decade / 10) * 10;
    int year_decade = model_year + 9;

    std::copy_if(cars.begin(), cars.end(),std::back_inserter(sorted_cars),
                 [model_year, year_decade](Car &year){return year.year >= model_year && year.year <= year_decade;});

    std::sort(sorted_cars.begin(), sorted_cars.end(),
              [](Car &value1, Car &value2){ return value1.value < value2.value;});

    return sorted_cars;

}


