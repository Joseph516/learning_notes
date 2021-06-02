#include <iostream>
#include <forward_list>

int main() {
    int data[] = {1,2,3,4,5,6,7,8,9};
    std::forward_list<int> flst(data, data+sizeof(data)/sizeof(int));
    for (const auto &v : flst) {
        std::cout << v << " ";
    }
    std::cout << "\n";

    // 删除奇数
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while(curr != flst.end()) {
        if ((*curr) %2 == 1) {
            curr = flst.erase_after(prev);
        } else{
            prev = curr;
            curr++;
        }
    }
    
    for (const auto &v : flst) {
        std::cout << v << " ";
    }
    std::cout << "\n";

}
