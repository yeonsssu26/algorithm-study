// https://gdlovehush.tistory.com/452
#include <iostream>
#include <vector>
#include <map> // key의 중복을 허락하지 않음
#include <algorithm>
using namespace std;
int N, C, num;
map<int, int> idx;	// {숫자, 해당 숫자가 처음 나타난 인덱스}
map<int, int> freq; // {숫자, 해당 숫자가 나타난 빈도}
vector<pair<int, int>> v;

bool Compare(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first) { // 두번째 조건 (인덱스 오름차순)
		return idx[a.second] < idx[b.second];
	}
	return a.first > b.first; // 첫번째 조건 (빈도 내림차순)
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> C;
	for (int n = 0; n < N; n++) {
		cin >> num;

		// num의 빈도를 1 증가시킨다
		freq[num]++;

		// num이 처음 나왔다면, 해당 인덱스를 저장한다
		if (idx[num] == 0) {
			idx[num] = n + 1;
		}
	}

	// freq {숫자, 빈도} -> {빈도, 숫자}로 바꿔서 벡터에 저장
	for (auto x : freq) {
		//v.push_back({ x.second, x.first });	// 같은결과 다른방법
		v.emplace_back(x.second, x.first);		// 같은결과 다른방법
	}

	// 빈도를 기준으로 정렬하되, 인덱스 조건 고려하여 정렬하도록 cmp 함수 적용
	sort(v.begin(), v.end(), Compare);

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].first; j++) { // 숫자의 빈도(v[i].first)만큼 숫자 출력
			cout << v[i].second << " ";
		}
	}
	return 0;
}