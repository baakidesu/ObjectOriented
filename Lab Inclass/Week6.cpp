// it is week 6 but practise name is week 4. FYI.

#include <iostream>
#include <memory>
#include <vector>

class Battery {
private:
    double weariness;
    int timesCharged;

public:

    Battery(double _weariness) {
        weariness = _weariness;
    }

    void Charge(int voltage) {
        if (timesCharged == 0) {
            weariness += 16;
        } else if (timesCharged == 1) {
            weariness += 12;
        } else if (timesCharged == 2) {
            weariness += 8;
        } else {
            weariness += (voltage >= 225) ? 4 : 1.5;
        }
        timesCharged++;
    }

    int GetTimesCharged() {
        return timesCharged;
    }

    double GetWeariness() {
        return weariness;
    }
};

void controlledCharge(std::shared_ptr<Battery> b, int _voltage) {
    if (b->GetTimesCharged() < 4) {
        b->Charge(220);
    }
    b->Charge(_voltage);
}

int main() {

    auto battery = std::make_shared<Battery>(3);
    int dumpVoltage;
    for (int i = 0; i < 5; i++) {
        std::cin >> dumpVoltage;
        controlledCharge(battery, dumpVoltage);
    }
    std:: cout << battery -> GetWeariness();
}