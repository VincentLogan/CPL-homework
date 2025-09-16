#include<stdio.h>
#include<stdlib.h>
#ifdef _WIN32
#include<windows.h>
#endif
int main(){
#ifdef _WIN32
    system("chcp 65001 > nul");
#endif

    int sum=0;
    char answer[11];
    printf("谁英雄，谁好汉，比一比，看一看\n");
    printf("为了巩固训练成果，强化动作要领掌握，现举行本次军训知识问答活动，请仔细阅读以下规则:\n\n");
    Sleep(500);
    printf("1.考察范围:题目均围绕单个军人队列动作条令，包括立正、稍息、停止间转法、齐步、跑步、正步等动作的各项要领、标准\n");
    printf("2.计分规则:本次问答总计一百分，共五道选择题，五道判断题，每小题答对得十分，答错不得分\n");
    printf("3.作答要求:请根据所学知识，独立思考，诚信作答，请勿使用AI工具\n");
    printf("4.温馨提示:回答问题请输入大写的“A/B/C/D”，输入小写字母或其他字母算作零分\n\n");
    Sleep(3000);

    printf("第一题【选择题】:站军姿时两脚张开约()度\nA.30° B.60° C.90° D.120°\n请输入你的答案:");
    scanf("%c",&answer[1]);
    if(answer[1]=='B')
    {
        sum+=10;
        printf("回答正确\n\n");
    }
    else{
        printf("回答错误，正确答案为B\n\n");
    }
    while(getchar()!='\n');
    Sleep(1000);

    printf("第二题【选择题】:练习站军姿时目光应该()\nA.直视前方\nB.向上仰视约45°\nC.盯着右前方同学的后脑勺\nD.紧盯教官\n请输入你的答案:");
    scanf("%c",&answer[2]);
    if(answer[2]=='A')
    {
        sum+=10;
        printf("回答正确\n\n");
    }
    else{
        printf("回答错误，正确答案为A\n\n");
    }
    while(getchar()!='\n');
    Sleep(1000);

    printf("第三题【选择题】:练习站军姿时身体前倾是为了()\nA.增加训练强度\nB.前倾看起来比较美观\nC.防止挤压后脚跟穴位,使大脑供血不足\nD.以上都不对\n请输入你的答案:");
    scanf("%c",&answer[3]);
    if(answer[3]=='C')
    {
        sum+=10;
        printf("回答正确\n\n");
    }
    else{
        printf("回答错误，正确答案为C\n\n");
    }
    while(getchar()!='\n');
    Sleep(1000);
    
    printf("第四题【选择题】:正步向前摆臂时，手腕摆到军训服胸口拉链下约()处\nA. 5厘米\nB. 10厘米\nC. 15厘米\nD. 与拉链齐平\n请输入你的答案:");
    scanf("%c",&answer[4]);
    if(answer[4]=='D')
    {
        sum+=10;
        printf("回答正确\n\n");
    }
    else{
        printf("回答错误，正确答案为D\n\n");
    }
    while(getchar()!='\n');
    Sleep(1000);
    
    printf("第五题【选择题】:“稍息”时，左脚顺脚尖方向伸出约全脚的()\nA. 1/3\nB. 2/3\nC. 1/2\nD. 全脚掌的距离\n请输入你的答案:");
    scanf("%c",&answer[5]);
    if(answer[5]=='B')
    {
        sum+=10;
        printf("回答正确\n\n");
    }
    else{
        printf("回答错误，正确答案为B\n\n");
    }
    while(getchar()!='\n');
    Sleep(1000);
    
    printf("第六题【判断题】:​齐步行进时，听到“立定”的口令，动令“定”落在右脚上\nA. 正确\nB. 错误\n请输入你的答案:");
    scanf("%c",&answer[6]);
    if(answer[6]=='A')
    {
        sum+=10;
        printf("回答正确\n\n");
    }
    else{
        printf("回答错误，正确答案为A(正确)\n【正确说法:齐步立定时，口令“立—定”的动令“定”通常落在右脚上，之后左脚再向前迈一步，右脚靠拢左脚成立正姿势】\n\n");
    }
    while(getchar()!='\n');
    Sleep(1000);
    
    printf("第七题【判断题】:戴帽敬礼时，手腕伸直，五指并拢，中指微接太阳穴\nA. 正确\nB. 错误\n请输入你的答案:");
    scanf("%c",&answer[7]);
    if(answer[7]=='B')
    {
        sum+=10;
        printf("回答正确\n\n");
    }
    else{
        printf("回答错误，正确答案为B(错误)\n【正确说法:中指微接帽檐右角前约2厘米处】\n\n");
    }
    while(getchar()!='\n');
    Sleep(1000);
    
    printf("第八题【判断题】:踢正步时，手心朝下\nA. 正确\nB. 错误\n请输入你的答案:");
    scanf("%c",&answer[8]);
    if(answer[8]=='B')
    {
        sum+=10;
        printf("回答正确\n\n");
    }
    else{
        printf("回答错误，正确答案为B(错误)\n【正确说法:手心朝向自己】\n\n");
    }
    while(getchar()!='\n');
    Sleep(1000);
    
    printf("第九题【判断题】:当下达向右转的口令时，右脚跟用力，身体旋转90°\nA. 正确\nB. 错误\n请输入你的答案:");
    scanf("%c",&answer[9]);
    if(answer[9]=='B')
    {
        sum+=10;
        printf("回答正确\n\n");
    }
    else{
        printf("回答错误，正确答案为B(错误)\n【正确说法:转体时，左前掌发力】\n\n");
    }
    while(getchar()!='\n');
    Sleep(1000);
    
    printf("第十题【判断题】:标兵为每排最右侧的同学，齐步走时应向右标齐\nA. 正确\nB. 错误\n请输入你的答案:");
    scanf("%c",&answer[10]);
    if(answer[10]=='A')
    {
        sum+=10;
        printf("回答正确\n\n");
    }
    else{
        printf("回答错误，正确答案为A(正确)\n\n");
    }
    while(getchar()!='\n');
    Sleep(1000);

    if(sum<60)
    {
        printf("你的总分为：%d【不及格】\n​“始于条令，归于条令”​。请你认真复习错题，从零开始，认真背诵和理解条令，迎头赶上！我们期待你下一次的显著进步！",sum);
    }
    else if(sum>=60&&sum<=80)
    {
        printf("你的总分为：%d【良好】\n“平时多流汗，战时少流血”​。理论是实践的先导，本次成绩表明你已为训练打下了良好基础，但距离“顶尖”还差最后一公里。不要满足于“差不多”，要追求“百分百”，望你刻苦钻研，力争满分!",sum);
    }
    else
    {
        printf("你的总分为：%d【优秀】\n“武艺练不精，不算合格兵”​，你用实际行动证明了这一点。本次问答成绩突出，证明你在理论层面已是一名“精兵”。接下来，要在训练实践中将理论发挥到极致，争取成为队列训练的“标兵”!",sum);
    }
    Sleep(10000);
    return 0;
}