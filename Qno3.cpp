#include <iostream>
#include <string>
#include <chrono>

class HeartRates {
private:
    std::string firstName, lastName;
    int month, day, year;

public:
    HeartRates(std::string FName, std::string LName, int mon, int da, int ye)
        : firstName(FName), lastName(LName), month(mon), day(da), year(ye) {}

    void setFirstName(std::string FName) {
        firstName = FName;
    }

    std::string getFirstName() const {
        return firstName;
    }

    void setLastName(std::string LName) {
        lastName = LName;
    }

    std::string getLastName() const {
        return lastName;
    }

    void setBirthDate(int mon, int da, int ye) {
        month = mon;
        day = da;
        year = ye;
    }

    std::string getBirthDate() const {
        return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
    }

    int getAge() const {
        auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        struct tm tm_now;

#if defined(_MSC_VER)
        localtime_s(&tm_now, &now);
#else
        localtime_r(&now, &tm_now);
#endif

        int age = tm_now.tm_year + 1900 - year;

        if (tm_now.tm_mon < month || (tm_now.tm_mon == month && tm_now.tm_mday < day)) {
            age--;
        }

        return age;
    }

    int MaximumHeartRate() const {
        return 220 - getAge();
    }

    void targetHeartRate() const {
        std::cout << "Target Heart Rate Range: " << MaximumHeartRate() * 0.5 << " to " << MaximumHeartRate() * 0.85 << std::endl;
    }
};

int main() {
    std::string firstName, lastName;
    int month, day, year;

    std::cout << "Enter First Name: ";
    std::cin >> firstName;

    std::cout << "Enter Last Name: ";
    std::cin >> lastName;

    std::cout << "Enter BirthDate with spaces (MM DD YYYY): ";
    std::cin >> month >> day >> year;

    HeartRates myHeartRate(firstName, lastName, month, day, year);

    std::cout << "Name: " << myHeartRate.getFirstName() << ", " << myHeartRate.getLastName() << std::endl;
    std::cout << "Age in years: " << myHeartRate.getAge() << std::endl;
    std::cout << "Maximum Heartrate: " << myHeartRate.MaximumHeartRate() << std::endl;
    myHeartRate.targetHeartRate();

    return 0;
}


