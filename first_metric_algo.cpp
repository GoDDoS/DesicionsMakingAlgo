#include <algorithm>
#include <iostream>
#include <vector>

struct Three {
    int first_param;
    int second_param;
    int index;
};

bool comp(Three &a, Three &b) {
    if (a.first_param < b.first_param) {
        return true;
    }
    if (a.first_param == b.first_param && a.second_param < b.second_param) {
        return true;
    }
    if (a.first_param == b.first_param && a.second_param == b.second_param && a.index < b.index) {
        return true;
    }
    return false;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Three> first_player(n), second_player(n);
    int a, b;
    for (int i = 0; i < n; ++i) {
        std::cin >> a >> b;
        first_player[i].first_param = second_player[i].second_param = a;
        first_player[i].second_param = second_player[i].first_param = b;
        first_player[i].index = second_player[i].index = i;
    }
    std::sort(first_player.begin(), first_player.end(), comp);
    std::sort(second_player.begin(), second_player.end(), comp);
    int current_player = (n + 1) % 2 + 1;
    std::vector<bool> is_used(n);
    int first_utility = 0, second_utility = 0;
    int first = 0, second = 0, gotcha = 0;
    for (int i = 0; i < n; ++i) {
        if (current_player == 1) {
            while (is_used[second_player[second].index]) {
                ++second;
            }
            first_utility += second_player[second].second_param;
            is_used[second_player[second].index] = true;
            ++second;
            current_player = 2;
        }
        else {
            while (is_used[first_player[first].index]) {
                ++first;
            }
            second_utility += first_player[first].second_param;
            is_used[first_player[first].index] = true;
            ++first;
            current_player = 1;
        }
    }
    std::cout << first_utility << " " << second_utility;
    return 0;
}