/*** 
 * @Author: szf
 * @Date: 2022-12-23 17:22:18
 * @LastEditTime: 2022-12-23 17:31:40
 * @LastEditors: szf
 * @Description: STL常用算法
 * @FilePath: \Study-Code\demo_34.cpp
 * @@WeChat:szf13373959031
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


//* 常见算法
// for_each()	对每个元素进行操作 \
// count()	返回元素个数
// count_if()	返回满足某条件的元素个数
// min_element()	最小元素
// max_element	最大元素
// find()	搜寻等于某值的第一个元素
// find_if()	搜寻满足某个条件的第一个元素
// search_n()	搜寻前n个连续匹配值
// search()	搜寻某个子区间第一个出现的位置
// find_end()	查询最后一次出现位置
// find_first_of()	搜寻某个数的第一个元素
// adjacent_find()	搜寻连续两个相对的元素
// equal()	判断两个区间是否相等
// mismatch()	返回两个序列的各组对应元素中，第一个不相等的元素
// lexicographical_cpmpare()	判断某一序列再字典顺序下是否小于另一序列

// for_each()	对每个元素执行操作
// copy()	第一元素开始复制某段区间
// copy_backward()	从最后一个开始，复制某段区间
// transform()	变动并复制元素 【速度较慢，需要返回赋值给元素】
// merge()	合并两个区间【要求已序】
// swap_ranges()	交换两个区间的元素
// fill()	以给定值替换每一个元素
// fill_n()	以给定值替换n个元素
// generate()	以某项操作的结果替换每一个元素
// generate_n()	以某项操作的结果替换n个元素
// replace()	将具有特值的元素替换为另一个值
// replace_if()	将符合某准则的元素替换为另一个值
// replace_copy()	复制整个区间，同时并将具有某特定值的元素替换为另一个值
// replace_copy_if()	复制整个区间，同时并将符合某个准则的元素替换为另一个值

//* 移除性算法
// remove()	将移除特定值的全部元素
// remove_if()	移除满足某条件的所有元素
// remove_copy()	将不等于某特定值元素全部复制到其它处
// remove_copy_if()	将不满足某条件的元素全部复制到其他处
// unique()	移除相邻的重复元素
// unique_copy()	移除相邻的重复元素，并复制到其他处

//* 变序性算法
// reverse()	将元素的次序逆转
// reverse_copy()	复制的同时，逆转元素顺序
// rotate()	旋转元素次序
// rotate_copy()	复制同时，旋转元素次序
// next_permutation()	得到元素的下一个排序次序
// prev_permutation()	得到元素的上一个排序次序
// random_shuffle()	将元素次序打乱
// partition()	改变元素次序，使符合某准则的移动到前面
// stable_partition()	与上一个相似，但保持符合准则与不符合准则之各个元素之间的相对位置

//* 排序算法
// sort()	排序；快速排序方法，有较好的平均性能O(n*logn)，但也有最差的情况
// stable_sort()	排序，并保持相等元素间的相对次序；归并排序，当有足够内存O(n*log(n))，否则O(n*logn*logn)
// partial_sort()	排序，直到前n个元素就位；堆排序，任何情况下下O(nlog(n))，速度比快排慢
// partial_sort_copy()	排序，直到前n个元素就位，结果复制到其他处
// nth_element()	根据第n个位置进行排序
// parition()	改变元素次序，满足某条件的放前面
// stable_partition()	与parition相同，但保持符合准则和不符合准则的各个元素之间的相对位置
// make_heap()	将一个区间转换为一个heap
// push_heap()	将元素加入一个heap
// pop_heap()	从heap移除一个元素
// sort_heap()	对heap进行排序，执行后不再是heap

//* 已序区间算法
// binary_search()	判断某区间内是否包含某个元素
// includes()	判断某区间内的每一个元素是否都涵盖于另一个区间中
// lower_bound()	搜寻第一个大于给定值的元素
// upper_bound()	搜寻第一个大于给定值的元素
// equal_range()	返回等于给定值的所有元素构成的区间
// merge()	将两个区间的元素合并
// set_union()	求两个区间的并集
// set_intersection()	求两个区间的交集
// set_difference()	求位于第一区间但不位于第二区间的所有元素，形成一个已序区间
// set_symmetric_difference()	找出只出现于两区间之一的所有元素，形成一个已序区间
// inplace_merge()	将两个连续的已序区间合并

//* 数值算法
// accumulate()	组合所有元素（求和、积等）
// inner_product()	组合两区间内的所有元素
// adjacent_difference()	将每个元素和其前一元素组合
// partial_sum()	将每个元素和其先前的所有元素组合


int main()
{
    system("pause");
    return 0;
}
