module;

#include <set>
#include <vector>
#include <string_view>
#include <ranges>

export module input;

export namespace input {
std::string day25_small = R"(string day25_small = R"(#####
.####
.####
.####
.#.#.
.#...
.....

#####
##.##
.#.##
...##
...#.
...#.
.....

.....
#....
#....
#...#
#.#.#
#.###
#####

.....
.....
#.#..
###..
###.#
###.#
#####

.....
.....
.....
#....
#.#..
#.#.#
#####)";

std::string day25 =  R"()";

std::vector<std::set<std::pair<int,int>>> parsed(std::string_view in) {
   std::vector<std::set<std::pair<int,int>>> result{{}};
   int y = 0;
   
   for (auto line : in | std::views::split('\n')) {
       if (line.empty()) {
           result.emplace_back();
           y = 0;
           continue;
       }
       
       for (int x = 0; x < line.size(); x++) {
           if (line[x] == '#') {
               result.back().emplace(x, y);
           }
       }
       y++;
   }
   return result;
}

}
