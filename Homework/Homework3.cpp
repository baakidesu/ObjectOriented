#include <iostream>

class Park {

    double widht, depth, mounthlyCleaningCount;
    int smallTrees, bigTrees;

    double usableSize, ratio;
    std::string parkQuality;

    double CalculateTotalUsableParkSize() {
        return ((widht * depth) - (0.75 * smallTrees) - (1.25 * bigTrees));
    }

    double CalculateRatio() {
        return (usableSize / (smallTrees + bigTrees));
    }

    std::string SetParkQuality() {
        if (mounthlyCleaningCount<2 && ratio > 20) {
            return "bad";
        }else if(mounthlyCleaningCount >= 2 && ratio > 20) {
            return "poor";
        }else if (mounthlyCleaningCount >= 2 && ratio <= 20) {
            return "fine";
        }else {
            return "good";
        }
    }

    public:

    Park(double w, double d, int sT, int bT, double mCC) {
        widht=w;
        depth=d;
        smallTrees = sT;
        bigTrees = bT;
        mounthlyCleaningCount=mCC;

        usableSize=CalculateTotalUsableParkSize();
        ratio=CalculateRatio();
        parkQuality=GetParkQuality();
    }

    double GetTotalUsableParkSize() {
        return usableSize;
    }

    std::string GetParkQuality() {
        return parkQuality;
    }

    std::string GetOverallParkQuality(std::string park1, std::string park2) {
        if (park1=="bad" || park2=="bad") {
            return "bad";
        }else if (park1=="poor" || park2=="poor") {
            return "poor";
        }else if (park1=="fine" || park2=="fine") {
            return "fine";
        }

        return "good";
    }
};


int main() {

    double w1, d1, mC1, w2, d2, mC2;
    int sT1, bT1, sT2, bT2;

    std::cin >> w1 >> d1 >> sT1 >> bT1 >> mC1;
    Park park1(w1, d1, sT1, bT1, mC1);

    std::cin >> w2 >> d2 >> sT2 >> bT2 >> mC2;
    Park park2(w2, d2, sT2, bT2, mC2);

    std::cout << park1.GetTotalUsableParkSize() + park2.GetTotalUsableParkSize() <<" ";
    std::cout << park1.GetOverallParkQuality(park1.GetParkQuality(), park2.GetParkQuality());
    return 0;
}
