#include <cassert>   // 用于断言测试
#include <iostream>  // 用于输入输出
#include <string>    // 用于字符串操作
#include <algorithm> // 用于 std::max
#include<cstdint>
namespace divide_and_conquer {
namespace karatsuba_algorithm {

/**
 * @brief 两个二进制字符串的加法函数
 * @param first  第一个二进制字符串，如 "101"
 * @param second 第二个二进制字符串，如 "11"
 * @returns 两数相加后的二进制字符串，如 "1000"
 */
std::string add_strings(std::string first, std::string second) {
    size_t len1 = first.size(); // 获取第一个字符串长度
    size_t len2 = second.size(); // 获取第二个字符串长度
    size_t n = std::max(len1, len2); // 取最大长度用于对齐

    // 补前导零，使两个字符串长度相等
    if (len1 < n) {
        first = std::string(n - len1, '0') + first; // 在前面补 '0'
    }
    if (len2 < n) {
        second = std::string(n - len2, '0') + second;
    }

    std::string result = ""; // 存储结果字符串
    int carry = 0; // 进位标志

    // 从最低位（最右边）开始逐位相加
    for (int i = n - 1; i >= 0; --i) {
        int bit1 = first[i] - '0'; // 字符转数字：'1' -> 1, '0' -> 0
        int bit2 = second[i] - '0';
        int total = bit1 + bit2 + carry; // 当前位总和

        result = char('0' + (total % 2)) + result; // 当前位结果（0 或 1）
        carry = total / 2; // 更新进位（0 或 1）
    }

    // 如果最后还有进位，需在最前面加 '1'
    if (carry) {
        result = '1' + result;
    }

    return result;
}

/**
 * @brief 安全地从二进制字符串中提取子串（考虑前导零）
 * @param str 原始二进制字符串（可能缺少前导零）
 * @param x1  起始位置（在完整长度为 n 的字符串中的索引）
 * @param x2  子串长度
 * @param n   完整长度（包括前导零）
 * @returns 提取的子串，若全为前导零则返回 "0"
 *
 * 示例：str = "101", n = 5 → 逻辑上是 "00101"
 *       safe_substr(str, 0, 2, 5) → 取前两位 "00" → 返回 "0"（去前导零）
 */
std::string safe_substr(const std::string &str, int64_t x1, int64_t x2, int64_t n) {
    int64_t len = str.size();

    // 如果当前字符串长度已达到 n，直接使用 substr
    if (len >= n) {
        return str.substr(x1, x2);
    }

    // 计算在实际字符串 str 中的起始和结束索引
    int64_t y1 = x1 - (n - len);  // 实际起始索引
    int64_t y2 = (x1 + x2 - 1) - (n - len); // 实际结束索引

    // 情况1：整个子串都在前导零区域
    if (y2 < 0) {
        return "0";
    }
    // 情况2：部分在前导零区域
    else if (y1 < 0) {
        return str.substr(0, y2 + 1); // 从 str 开头取到 y2
    }
    // 情况3：完全在 str 范围内
    else {
        return str.substr(y1, x2);
    }
}

/**
 * @brief Karatsuba 快速乘法算法（递归实现）
 * @param str1 第一个二进制字符串
 * @param str2 第二个二进制字符串
 * @returns 两个二进制数相乘的结果（十进制整数，int64_t 类型）
 *
 * 算法原理：
 * 设 X = Xl * 2^m + Xr, Y = Yl * 2^m + Yr
 * 则 XY = XlYl*2^{2m} + (XlYr + XrYl)*2^m + XrYr
 * 使用 Karatsuba 优化：只需计算 3 次乘法
 * P1 = Xl*Yl, P2 = Xr*Yr, P3 = (Xl+Xr)(Yl+Yr)
 * 结果 = P1*2^{2m} + (P3 - P1 - P2)*2^m + P2
 */
int64_t karatsuba_algorithm(std::string str1, std::string str2) {
    int64_t len1 = str1.size();
    int64_t len2 = str2.size();
    int64_t n = std::max(len1, len2); // 统一长度 n

    // 基本情况：长度为 0 或 1
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return (str1[0] - '0') * (str2[0] - '0'); // 直接相乘
    }

    int64_t fh = n / 2;     // 前半部分长度
    int64_t sh = n - fh;    // 后半部分长度（用于位移）

    // 使用 safe_substr 分割字符串（自动处理前导零）
    std::string Xl = safe_substr(str1, 0, fh, n); // 高位部分
    std::string Xr = safe_substr(str1, fh, sh, n); // 低位部分

    std::string Yl = safe_substr(str2, 0, fh, n);
    std::string Yr = safe_substr(str2, fh, sh, n);

    // 递归计算三个乘积
    int64_t P1 = karatsuba_algorithm(Xl, Yl); // Xl * Yl
    int64_t P2 = karatsuba_algorithm(Xr, Yr); // Xr * Yr
    int64_t P3 = karatsuba_algorithm(
        add_strings(Xl, Xr),   // (Xl + Xr)
        add_strings(Yl, Yr)    // (Yl + Yr)
    ); // (Xl+Xr)(Yl+Yr)

    // 合并结果：P1 * 2^(2*sh) + (P3 - P1 - P2) * 2^(sh) + P2
    // 使用位移模拟乘以 2 的幂
    return P1 * (1LL << (2 * sh)) +          // 高位部分左移 2*sh 位
           (P3 - P1 - P2) * (1LL << sh) +    // 中间部分左移 sh 位
           P2;                                // 低位部分
}

}  // namespace karatsuba_algorithm
}  // namespace divide_and_conquer

/**
 * @brief 自测函数：验证算法正确性
 */
static void test() {
    // 测试 1: 1 * 10 = 10
    std::string s11 = "1";      // 二进制: 1 -> 十进制: 1
    std::string s12 = "1010";   // 二进制: 1010 -> 十进制: 10
    std::cout << "测试 1... ";
    assert(divide_and_conquer::karatsuba_algorithm::karatsuba_algorithm(s11, s12) == 10);
    std::cout << "通过" << std::endl;

    // 测试 2: 3 * 10 = 30
    std::string s21 = "11";     // 3
    std::string s22 = "1010";   // 10
    std::cout << "测试 2... ";
    assert(divide_and_conquer::karatsuba_algorithm::karatsuba_algorithm(s21, s22) == 30);
    std::cout << "通过" << std::endl;

    // 测试 3: 6 * 10 = 60
    std::string s31 = "110";    // 6
    std::string s32 = "1010";   // 10
    std::cout << "测试 3... ";
    assert(divide_and_conquer::karatsuba_algorithm::karatsuba_algorithm(s31, s32) == 60);
    std::cout << "通过" << std::endl;

    // 可选：添加更多测试，如 0 * x, x * 0, 大数等
}

/**
 * @brief 主函数
 * @returns 0 表示程序正常结束
 */
int main() {
    test();  // 运行测试
    std::cout << "所有测试通过！" << std::endl;
    return 0;
}