# 영어 대소문자와 띄어쓰기만으로 이루어진 문자열이 주어진다. 이 문자열에는 몇 개의 단어가 있을까?
givenString = input()
wordsList = []
if (givenString == ' '):
    print(0)
else:
    wordsList.extend(givenString.strip().split(' '))
    print(len(wordsList))