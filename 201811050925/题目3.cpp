#include "iostream"
#include "algorithm"
using namespace std;

struct student {
	int chinese;//���ĳɼ�
	int math;//��ѧ�ɼ�
	int english;//Ӣ��ɼ�
	int num;//���
	int sum;//�ܷ�
}s[100];

int cmp(student p1, student p2) {
	if (p1.sum == p2.sum && p1.chinese != p2.chinese) {
		return p1.chinese > p2.chinese;
	}//�ܷ���ͬ�����ĳɼ�������ǰ
	if (p1.sum == p2.sum && p1.chinese == p2.chinese) {
		return p1.num < p2.num;
	}//�ܷ���ͬ�����ĳɼ���ͬ�����С��ǰ
	else {
		return p1.sum > p2.sum;
	}//�����ܷ�Խ����Խǰ
}
int main()
{
	int n;//����
    cout<<"���������ѧ������:"; 
	cin >> n;
	for (int i = 1; i <= n; i++) {
		s[i].num = i;
		cin >> s[i].chinese >> s[i].math >> s[i].english;
		s[i].sum = s[i].chinese + s[i].math + s[i].english;
	}
	sort(1 + s, 1 + n + s, cmp);//����

	for (int i = 1; i <= 5; i++) 
	{//���ǰ5��
		cout << s[i].num << "  " << s[i].sum << endl;;
	}
	return 0;
}
