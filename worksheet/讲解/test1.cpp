#include <iostream>
using namespace std;

float mypower(int m , int n){
	float r = 1;                // 因为要求保留小数，所以声明一个 float 类型的 r；
	int a = n;
	if(a < 0){                  // 防止n为负数时 i <= a 不成立，for循环不运行
		a = -a;
	}
	if(n != 0){
		for (int i = 1; i <= a; i++)          // 一共循环 n 轮 ，当n < 0 时则为 -n 轮
		{
			r = r * m;          // 每轮乘一个 m， 共 n 轮，让 r = m的n次幂
		}
		if(n < 0){            
			r = 1/r;           // 当n为负数时，求得的结果应为r的倒数
		}
		return r;
	} else {                  
		return 1;              // 如果 n = 0，结果应为1，直接返回1
	} 
}

int main(void){
	int m = 0;
	int n = 0;
	float answer;
	cin >> m >> n;
	
	answer = mypower(m , n);       // 让answer等于自定义函数返回的值
	
	printf("%.2f" , answer);       // %.2f 保留两位小数，满足输出格式要求
	return 0;
}