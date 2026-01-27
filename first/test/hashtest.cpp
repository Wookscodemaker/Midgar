#include <iostream>
#include <vector>
#include <list>
#include <string>

// 哈希表类模板
template <typename K, typename V>
class HashTable {
private:
    // 哈希表的大小
    size_t tableSize;
    // 存储键值对的桶，每个桶是一个链表
    std::vector<std::list<std::pair<K, V>>> buckets;
    
    // 哈希函数，将键转换为索引
    size_t hashFunction(const K& key) const {
        // 对于字符串类型的键，使用一个简单的哈希函数
        if constexpr (std::is_same_v<K, std::string>) {
            size_t hash = 0;
            for (char c : key) {
                hash = 37 * hash + c;
            }
            return hash % tableSize;
        }
        // 对于其他类型，使用取模运算
        else {
            return std::hash<K>()(key) % tableSize;
        }
    }
    
    // 检查是否需要扩容
    void checkResize() {
        // 计算负载因子
        size_t totalElements = 0;
        for (const auto& bucket : buckets) {
            totalElements += bucket.size();
        }
        
        // 如果负载因子超过0.7，则扩容
        if (static_cast<double>(totalElements) / tableSize > 0.7) {
            resize(tableSize * 2);
        }
    }
    
    // 扩容哈希表
    void resize(size_t newSize) {
        // 创建新的桶数组
        std::vector<std::list<std::pair<K, V>>> newBuckets(newSize);
        
        // 将旧桶中的元素重新哈希到新桶中
        for (const auto& bucket : buckets) {
            for (const auto& pair : bucket) {
                size_t newIndex = std::hash<K>()(pair.first) % newSize;
                newBuckets[newIndex].push_back(pair);
            }
        }
        
        // 更新哈希表的大小和桶数组
        tableSize = newSize;
        buckets.swap(newBuckets);
    }

public:
    // 构造函数
    HashTable(size_t size = 16) : tableSize(size), buckets(size) {}
    
    // 插入键值对
    void insert(const K& key, const V& value) {
        // 计算哈希值
        size_t index = hashFunction(key);
        
        // 检查键是否已存在，如果存在则更新值
        for (auto& pair : buckets[index]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        
        // 如果键不存在，则添加新的键值对
        buckets[index].push_back(std::make_pair(key, value));
        
        // 检查是否需要扩容
        checkResize();
    }
    
    // 查找键对应的值
    V* find(const K& key) {
        // 计算哈希值
        size_t index = hashFunction(key);
        
        // 在对应桶中查找键
        for (auto& pair : buckets[index]) {
            if (pair.first == key) {
                return &pair.second;
            }
        }
        
        // 键不存在，返回 nullptr
        return nullptr;
    }
    
    // 删除键值对
    bool remove(const K& key) {
        // 计算哈希值
        size_t index = hashFunction(key);
        
        // 在对应桶中查找并删除键
        auto& bucket = buckets[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return true;
            }
        }
        
        // 键不存在，返回 false
        return false;
    }
    
    // 打印哈希表的内容
    void print() const {
        for (size_t i = 0; i < tableSize; ++i) {
            std::cout << "Bucket " << i << ": ";
            for (const auto& pair : buckets[i]) {
                std::cout << "[" << pair.first << ", " << pair.second << "] ";
            }
            std::cout << std::endl;
        }
    }
};

// 主函数，测试哈希表
int main() {
    // 创建一个字符串到整数的哈希表
    HashTable<std::string, int> hashTable;
    
    // 插入一些键值对
    hashTable.insert("apple", 10);
    hashTable.insert("banana", 20);
    hashTable.insert("orange", 30);
    hashTable.insert("grape", 40);
    hashTable.insert("watermelon", 50);
    
    // 打印哈希表的内容
    std::cout << "哈希表初始状态：" << std::endl;
    hashTable.print();
    std::cout << std::endl;
    
    // 测试查找操作
    std::string key = "banana";
    int* value = hashTable.find(key);
    if (value) {
        std::cout << "查找键 '" << key << "' 的值: " << *value << std::endl;
    } else {
        std::cout << "键 '" << key << "' 不存在" << std::endl;
    }
    
    key = "pear";
    value = hashTable.find(key);
    if (value) {
        std::cout << "查找键 '" << key << "' 的值: " << *value << std::endl;
    } else {
        std::cout << "键 '" << key << "' 不存在" << std::endl;
    }
    std::cout << std::endl;
    
    // 测试更新操作
    hashTable.insert("apple", 100); // 更新已存在的键
    std::cout << "更新键 'apple' 的值后：" << std::endl;
    hashTable.print();
    std::cout << std::endl;
    
    // 测试删除操作
    key = "orange";
    if (hashTable.remove(key)) {
        std::cout << "删除键 '" << key << "' 成功" << std::endl;
    } else {
        std::cout << "删除键 '" << key << "' 失败" << std::endl;
    }
    
    std::cout << "删除键 'orange' 后：" << std::endl;
    hashTable.print();
    std::cout << std::endl;
    
    // 测试扩容（插入更多元素）
    std::cout << "插入更多元素以触发扩容：" << std::endl;
    for (int i = 0; i < 20; ++i) {
        hashTable.insert("key" + std::to_string(i), i * 10);
    }
    hashTable.print();
    
    return 0;
}
