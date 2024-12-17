#ifndef MAIN_HPP
#define MAIN_HPP
#include <string>
#include <array>

struct WeedInfo {
    std::string name;
    int weeds;
    double value;
};

const WeedInfo Sword{
    "Base",
    0,
    658225
};

constexpr std::array<WeedInfo, 8> WeedTiers{
    WeedInfo
    {
        "Tier0",
        1,
        84016,
    },
    {
        "Tier1",
        2,
        138626.4,
    },
    {
        "Tier2",
        4,
        228733.56,
    },
    {
        "Tier3",
        8,
        377410.374,
    },
    {
        "Tier4",
        16,
        622727.1171,
    },
    {
        "Tier5",
        32,
        1027499.743215,
    },
    {
        "Tier6",
        64,
        1695374.5763047498,
    },
    {
        "Tier7",
        128,
        2797368.0509028374,
    },
};


inline double calcStat(double b, double bt, double m, double mt) {
    double beneficiary = bt * b;
    double material = mt * m;

    return (beneficiary + bt * ((beneficiary + material) / 2 - beneficiary)) / bt;
}

inline double technoFuse(double b, double m) {
    return calcStat(b, 0.2, m, 1.5);
}


#endif //MAIN_HPP
