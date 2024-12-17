#include "main.hpp"
#include <iostream>
#include <optional>
#include <vector>

struct Solution {
    double currentValue = 0;
    std::vector<const WeedInfo *> weeds;
    int numWeeds = 0;
};

const double targetValue = 5000000;
const int worstCase = 512;

void solve(Solution& base, Solution& shortest) {
    for (const WeedInfo& weedInfo: WeedTiers) {
        auto oldValue = base.currentValue;

        auto newValue = technoFuse(base.currentValue, weedInfo.value);
        auto newNumWeeds = base.numWeeds + weedInfo.weeds;

        if (newValue <= base.currentValue) continue;
        if (newNumWeeds > worstCase + 1) continue;
        if (newValue > targetValue) {
            if (newNumWeeds < shortest.numWeeds) {
                shortest = base;
                shortest.weeds.emplace_back(&weedInfo);
                shortest.currentValue = newValue;
                shortest.numWeeds = newNumWeeds;
            }
            continue;
        }

        base.weeds.emplace_back(&weedInfo);
        base.numWeeds += weedInfo.weeds;
        base.currentValue = newValue;

        solve(base, shortest);
        base.weeds.pop_back();

        base.numWeeds -= weedInfo.weeds;
        base.currentValue = oldValue;
    }
}

int main() {
    Solution base{
        .currentValue = Sword.value,
        .weeds = {},
        .numWeeds = 0
    };

    Solution shortest{
        .numWeeds = worstCase + 1
    };

    solve(base, shortest);

    std::cout << "Num weeds: " << shortest.numWeeds << std::endl;
    std::cout << "Base";
    for (auto tier: shortest.weeds) {
        std::cout << " -> " << tier->name;
    }

    return 0;
}
