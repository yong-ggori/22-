#include <string>
#include <vector>
#include <algorithm>    // sort ���� �Լ� ��� ���� ��� ���� ����
#include <iostream>

using namespace std;

bool numCompare(string, string);    // ����� ���� �Լ� ����
/*
���� �� �� �� ���� ��Ҹ� �� �ϴµ� �� �� ���ڸ� 
�����ؼ� ���� �� �ִ� ���� ū ���� ���ϱ� ���ؼ��� int���� �ƴ� string������ �ϴ� ���� ���ϴ�.

���� ��� 3�� 15��� ���ڸ� �����ؼ� ���Ѵٰ� ����. 
int������ �� �� 3 + 15, 15 + 3�� �� �� 18�̴�. 
������ string������ �ϰ� �Ǹ� ��3�� + ��15�� = ��315���� �� ���̰�, ��15�� + ��3�� = ��153���� �� ���̴�.

�� �� ���� ���ϸ� � ���� �� Ŀ�� ������ �� ������ �� ����.
������ int �� numbers�� string ������ �ٲپ� ���� �ϰ� sort ������ ���� �Լ��� �����
���ؼ� ����ϴ� ���� ��ǥ�� �Ѵ�.
*/
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strNumbers;
    for (auto n : numbers)
        strNumbers.push_back(to_string(n)); // int�� -> string������ ����
    
    // sort(verctor�� ù ��° �ּ�, vector�� ������ �ּ�, ����� ���� �Լ�)
    // ���� �ϰ��� �ϴ� vector�� ������ �����Ѵ�.
    sort(strNumbers.begin(), strNumbers.end(), numCompare);
    for (int idx = 0; idx < strNumbers.size(); idx++)
        answer += strNumbers.at(idx);

    // ��� ������ 0 �� �� string������ ���ϱ� ������
    // "00000.." �� ��µȴ�. ��� ���� 0 �϶�
    // "0" �� ��µǰ� �ϱ� ���� �Ʒ� �ڵ带 �߰� �ߴ�.
    if (answer.at(0) == '0') answer = '0';

    return answer;
}
bool numCompare(string num1, string num2) {
    return (num1 + num2) > (num2 + num1);
}
