import matplotlib.pyplot as plt
import pandas as pd

# 从你的表格中提取的 Duration 数据（单位：秒）
data = {
    'N': [100, 500, 1000, 2000, 4000, 6000, 8000, 10000],
    'Binary_Iter_Duration': [
        0.00000011, 0.00000022, 0.00000010, 0.00000011,
        0.00000015, 0.00000012, 0.00000012, 0.00000013
    ],
    'Binary_Recur_Duration': [
        0.00000018, 0.00000010, 0.00000012, 0.00000013,
        0.00000013, 0.00000014, 0.00000010, 0.00000015
    ],
    'Seq_Iter_Duration': [
        0.00000020, 0.00000130, 0.00000290, 0.00000560,
        0.00001010, 0.00001520, 0.00001880, 0.00002680
    ],
    'Seq_Recur_Duration': [
        0.00000240, 0.00000860, 0.00002380, 0.00004890,
        0.00009190, 0.00009610, 0.00015380, 0.00017300
    ]
}

# 转换为 pandas DataFrame（方便操作）
df = pd.DataFrame(data)

# 设置图形大小
plt.figure(figsize=(10, 6))

# 绘制四条曲线，使用不同的标记和颜色
plt.plot(df['N'], df['Binary_Iter_Duration'], 'o-', 
         label='Binary Search (Iterative)', color='blue')
plt.plot(df['N'], df['Binary_Recur_Duration'], 's-', 
         label='Binary Search (Recursive)', color='cyan')
plt.plot(df['N'], df['Seq_Iter_Duration'], '^-', 
         label='Sequential Search (Iterative)', color='red')
plt.plot(df['N'], df['Seq_Recur_Duration'], 'd-', 
         label='Sequential Search (Recursive)', color='orange')

# 关键：使用对数坐标（因为两种搜索时间相差几个数量级）
plt.yscale('log')

# 添加轴标签和标题
plt.xlabel('Data Size (N)', fontsize=12)
plt.ylabel('Average Time per Search (seconds)', fontsize=12)
plt.title('Performance Comparison of Search Algorithms', fontsize=14)

# 显示图例
plt.legend()

# 添加网格（便于读数）
plt.grid(True, which='both', linestyle='--', alpha=0.6)

# 保存图像到文件（高分辨率）
plt.savefig('search_performance.png', dpi=300, bbox_inches='tight')

# 显示图像（如果你的环境支持图形界面）
plt.show()