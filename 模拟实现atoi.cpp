int StrToInt (string str) {
    int len = str.length();
    //1.判断空串
    if (len == 0) return 0;
    int flag = false;
    int i = 0;
    int num = 0;
    //过滤前面的空格
    while (str[i] == ' ')
        i++;
    //判断有无符号
    if (str[i] == '-') {
        flag = true;
        i++;
    } else if (str[i] == '+') {
        i++;
    }
    //进行数值的转换
    while(str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            int sy = flag ? -1 : 1;
            num = num * 10 + sy * (str[i] - '0');
            // //处理溢出
            // if ((flag < 0)&&(num > 0x7FFFFFFF) || 
            //     (flag > 0)&&(num < 0x80000000)) {
            //     cout << "溢出" <<endl;
            //     return 0;
            // }
            i++;
        } else {
            break;
        }
    }
    return num;
}