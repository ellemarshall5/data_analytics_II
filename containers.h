#ifndef CONTAINERS_H_
#define CONTAINERS_H_

#include <string>
#include <vector>
#include <map>
#include <string>

// Operation for analytics
#define MAX 1
#define MIN 2

// TODO: Structure for data from file
struct Car
{
    std::string vin;
    std::string make;
    int year;
    std::string color;
    double value;
    std::string state;
};

void Load_Data(std::vector<Car> &cars, const std::string &in_file);
// TODO: Other functions

Car Car_Value_Analytics(std::vector<Car> &cars, int operation);

std::vector<Car> Cars_from_decade(std::vector<Car> &cars, int decade);

#endif /* !CONTAINERS_H_ */
