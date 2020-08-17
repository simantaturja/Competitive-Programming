class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector <int> people(num_people, 0);
        int add = 0;
        while (candies > 0) {
            for (int i = 1; i <= num_people; ++i) {
                if (candies - (add + i) >= 0) {
                    people[i - 1] += (add + i);
                    candies -= (add + i);
                } else {
                    people[i - 1] += candies;
                    candies = 0;
                    break;
                }
            }
            add += num_people;
        }
        return people;
    }
};
