#include <string>
#include <vector>

using namespace std;
/*
���� ��� ���� �Լ� �� at ���, ������ idx ��° ��� ���� �ϱ� ����
int �� �ڷ����� �޼հ� �������� ��ġ�� �� �� 10, 12�� ����

pair Ŭ������ Ű�е��� ��ǥ((0, 0) ~ (3, 2))�� ���� ������ ��
x ��ǥ�� ��ȭ�� + y ��ǥ�� ��ȭ������ �� �̵� �Ÿ��� ���Ѵ�.

������ Ű�е�� ���� ��ġ�� ���Ͽ� �Ÿ��� ��� ��
���� ª�� �Ÿ��� �ִ� ���� ��ġ�� �ش� Ű�е�� �̵�.

** Ű �е� **
   1  2  3
   4  5  6
   7  8  9
  10 11 12 (* 0 #)
************
*/
vector<pair<int, int>> locate = {
    {0, 0}, {0, 1}, {0, 2},
    {1, 0}, {1, 1}, {1, 2},
    {2, 0}, {2, 1}, {2, 2},
    {3, 0}, {3, 1}, {3, 2}
};
string solution(vector<int> numbers, string hand) {
    string answer = "";
    int rightHandPosi = 12, leftHandPosi = 10, rightHandDis, leftHandDis;
    // ó�� ������ ��ġ = 12, ó�� �޼� ��ġ = 10�� �ʱ�ȭ

    for (int idx = 0; idx < numbers.size(); idx++) {          // ������ ��ȣ ��ŭ �ݺ��� ����
        if (numbers.at(idx) == 0) numbers.at(idx) = 11;      // Ű�е� 0�� 11�� ���
        // 1, 4, 7�� ���� �� �޼� ���
        if (numbers.at(idx) == 1 || numbers.at(idx) == 4 || numbers.at(idx) == 7) {
            answer += 'L';
            leftHandPosi = numbers.at(idx);     // �޼� ��ġ ����
        }
        // 3, 6, 9�� ���� �� ���� �� ���
        else if (numbers.at(idx) == 3 || numbers.at(idx) == 6 || numbers.at(idx) == 9) {
            answer += 'R';
            rightHandPosi = numbers.at(idx);    // ������ ��ġ ����
        }
        // 2, 5, 8, 0�� ���� ��
        else {
            // ������ ��ġ���� ������ �� ��ư ������ �Ÿ�, x ��ǥ ��ȭ�� + y ��ǥ ��ȭ��
            rightHandDis = abs(locate[numbers.at(idx) - 1].first - locate[rightHandPosi - 1].first)
                         + abs(locate[numbers.at(idx) - 1].second - locate[rightHandPosi - 1].second);
            // �޼� ��ġ���� ������ �� ��ư ������ �Ÿ�
            leftHandDis = abs(locate[numbers.at(idx) - 1].first - locate[leftHandPosi - 1].first) 
                        + abs(locate[numbers.at(idx) - 1].second - locate[leftHandPosi - 1].second);
            if (rightHandDis > leftHandDis) {        // �޼��� �������� �� �Ÿ��� �� ���� ���
                answer += 'L';
                leftHandPosi = numbers.at(idx);
            }
            else if (rightHandDis < leftHandDis) {   // �������� �������� �� �Ÿ��� �� ���� ���
                answer += 'R';
                rightHandPosi = numbers.at(idx);
            }
            else if (rightHandDis == leftHandDis) {  // �� ���� ������ �Ÿ��� ���� ��
                if (hand == "left") {                // �޼� ������ ���
                    answer += 'L';
                    leftHandPosi = numbers.at(idx);
                }
                else if (hand == "right") {          // ������ ������ ���
                    answer += 'R';
                    rightHandPosi = numbers.at(idx);
                }
            }
        }
    }
    return answer;
}