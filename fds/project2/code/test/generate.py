# 该代码全部由 DeepSeek 生成,未经人工修改,仅仅用于生成大规模测试样例
# 使用方法：python3 generate.py <n1> <n2> [output_file_name]

import random
import sys

def generate_bst_nodes(n, min_val=-2_000_000_000, max_val=2_000_000_000):
    """
    生成包含 n 个节点的 BST，返回列表 [(value, parent_index), ...]
    节点索引从 0 到 n-1，根节点 parent_index = -1
    """
    if n == 0:
        return []
    
    # 生成 n 个不重复的随机值（BST 中值可重复，但去重可避免复杂处理）
    # 若 n > 可能的值范围，则会出现重复，但题目允许重复，但此处限制唯一值更简单
    # 实际 2e9 范围远大于 2e5，所以唯一值可行
    values = random.sample(range(min_val, max_val+1), n)
    
    # 随机决定根节点索引（0..n-1），但实际 BST 插入顺序影响形状
    # 为了得到合法 BST，我们按随机顺序插入，记录每个节点的父节点
    # 构建一个空 BST 结构（存储左右孩子和父节点）
    # 但最终输出需要的是每个节点的父节点索引（基于输入顺序）
    # 因此我们先生成所有节点值，然后打乱顺序插入，记录插入时的父节点。
    
    # 节点信息: (value, left, right, parent) 其中 left/right 存储节点索引，parent存储父节点索引
    nodes = [{'val': v, 'left': -1, 'right': -1, 'parent': -1} for v in values]
    
    # 插入顺序随机，保证树形状随机
    insert_order = list(range(n))
    random.shuffle(insert_order)
    
    # 根节点: 第一个插入的节点
    root_idx = insert_order[0]
    nodes[root_idx]['parent'] = -1
    
    # 用于快速查找 BST 节点（按值）? 但我们需要根据大小关系插入，需要从根开始比较
    # 由于插入顺序随机，我们维护一棵 BST 的索引结构
    for idx in insert_order[1:]:
        cur = root_idx
        while True:
            if nodes[idx]['val'] < nodes[cur]['val']:
                if nodes[cur]['left'] == -1:
                    nodes[cur]['left'] = idx
                    nodes[idx]['parent'] = cur
                    break
                else:
                    cur = nodes[cur]['left']
            else:  # >=
                if nodes[cur]['right'] == -1:
                    nodes[cur]['right'] = idx
                    nodes[idx]['parent'] = cur
                    break
                else:
                    cur = nodes[cur]['right']
    
    # 构建输出列表，按节点索引顺序（0..n-1）输出 value 和 parent
    result = []
    for i in range(n):
        result.append((nodes[i]['val'], nodes[i]['parent']))
    return result

def generate_test_case(n1, n2, N=None, min_val=-2_000_000_000, max_val=2_000_000_000):
    """
    生成完整的测试用例字符串
    """
    lines = []
    lines.append(str(n1))
    t1_nodes = generate_bst_nodes(n1, min_val, max_val)
    for val, parent in t1_nodes:
        lines.append(f"{val} {parent}")
    lines.append(str(n2))
    t2_nodes = generate_bst_nodes(n2, min_val, max_val)
    for val, parent in t2_nodes:
        lines.append(f"{val} {parent}")
    if N is None:
        # 随机生成 N，范围在 [min_val*2, max_val*2] 内，避免溢出
        N = random.randint(min_val*2, max_val*2)
    lines.append(str(N))
    return "\n".join(lines)

if __name__ == "__main__":
    # 示例：生成一个中等规模文件
    if len(sys.argv) < 3:
        print("Usage: python gen_bst.py <n1> <n2> [output_file]")
        sys.exit(1)
    n1 = int(sys.argv[1])
    n2 = int(sys.argv[2])
    output_file = sys.argv[3] if len(sys.argv) > 3 else "large_input.txt"
    
    content = generate_test_case(n1, n2)
    with open(output_file, "w") as f:
        f.write(content)
    print(f"Generated {output_file} with n1={n1}, n2={n2}")