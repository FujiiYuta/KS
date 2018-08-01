//計算数理課題
//8パズルの可解問題提示とそのチートプログラム
//displaying acceptable problem (quiz) of 8-puzzle's and cheat program of this.

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>
#include <queue>
#include <map>
#include <string>
#include <cstdio>

using namespace std;
const int H = 3;
const int W = 3;
const int MAX = 9;
int perm_check = 0;
int counter;
int FPuzzle[W][H];
int f = 0;

//クラスDepth
//深度を計算する際に使用
//prevが前の状態で
//depが深度
class Depth
{
public:
  int dep;
  string prev;
  Depth(string str, int dep1){
    prev = str;
    dep = dep1;
  }
};
int move(string str, string *res)
{
  //実際の交換の手順を表す。
  //交換できるのは隣接の数のみなので、その数の位置情報を記述
  //C++の公式ライブラリmapを使用した
  int l, m = 0;
  string str1;
  //0を見つける
  l = str.find("0");
  switch(l){
  case 0:
    str1 = str.replace(l, 1, str, l+3, 1);
    str1 = str1.replace(l+3, 1, 1, '0');
    res[m] = str1;
    m++;
    str1 = str.replace(l, 1, str, l+1, 1);
    str1 = str1.replace(l+1, 1, 1, '0');
    res[m] = str1;
    m++;
    break;
  case 1:
    str1 = str.replace(l, 1, str, l-1, 1);
    str1 = str1.replace(l-1, 1, 1, '0');
    res[m] = str1;
    m++;
    str1 = str.replace(l, 1, str, l+1, 1);
    str1 = str1.replace(l+1, 1, 1, '0');
    res[m] = str1;
    m++;
    str1 = str.replace(l, 1, str, l+3, 1);
    str1 = str1.replace(l+3, 1, 1, '0');
    res[m] = str1;
    m++;
    break;
  case 2:
    str1 = str.replace(l, 1, str, l-1, 1);
    str1 = str1.replace(l-1, 1, 1, '0');
    res[m] = str1;
    m++;
    str1 = str.replace(l, 1, str, l+3, 1);
    str1 = str1.replace(l+3, 1, 1, '0');
    res[m] = str1;
    m++;
    break;
  case 3:
    str1 = str.replace(l, 1, str, l-3, 1);
    str1 = str1.replace(l-3, 1, 1, '0');
    res[m] = str1;
    m++;
    str1 = str.replace(l, 1, str, l+1, 1);
    str1 = str1.replace(l+1, 1, 1, '0');
    res[m] = str1;
    m++;
    str1 = str.replace(l, 1, str, l+3, 1);
    str1 = str1.replace(l+3, 1, 1, '0');
    res[m] = str1;
    m++;
    break;
  case 4:
  str1 = str.replace(l, 1, str, l-3, 1);
    str1 = str1.replace(l-3, 1, 1, '0');
    res[m] = str1;
    m++;
    str1 = str.replace(l, 1, str, l-1, 1);
    str1 = str1.replace(l-1, 1, 1, '0');
    res[m] = str1;
    m++;
    str1 = str.replace(l, 1, str, l+1, 1);
    str1 = str1.replace(l+1, 1, 1, '0');
    res[m] = str1;
    m++;
    str1 = str.replace(l, 1, str, l+3, 1);
    str1 = str1.replace(l+3, 1, 1, '0');
    res[m] = str1;
    m++;
    break;
  case 5:
    str1 = str.replace(l, 1, str, l-3, 1);
    str1 = str1.replace(l-3, 1, 1, '0');
    res[m] = str1;
    m++;
    str1 = str.replace(l, 1, str, l-1, 1);
    str1 = str1.replace(l-1, 1, 1, '0');
    res[m] = str1;
    m++;
    str1 = str.replace(l, 1, str, l+3, 1);
    str1 = str1.replace(l+3, 1, 1, '0');
    res[m] = str1;
    m++;
    break;
  case 6:
    str1 = str.replace(l, 1, str, l-3, 1);
    str1 = str1.replace(l-3, 1, 1, '0');
    res[m] = str1;
    m++;
    str1 = str.replace(l, 1, str, l+1, 1);
    str1 = str1.replace(l+1, 1, 1, '0');
    res[m] = str1;
    m++;
    break;
  case 7:
    str1 = str.replace(l, 1, str, l-3, 1);
    str1 = str1.replace(l-3, 1, 1, '0');
    res[m] = str1;
    m++;
    str1 = str.replace(l, 1, str, l-1, 1);
    str1 = str1.replace(l-1, 1, 1, '0');
    res[m] = str1;
    m++;
    str1 = str.replace(l, 1, str, l+1, 1);
    str1 = str1.replace(l+1, 1, 1, '0');
    res[m] = str1;
    m++;
    break;
  case 8:
    str1 = str.replace(l, 1, str, l-1, 1);
    str1 = str1.replace(l-1, 1, 1, '0');
    res[m] = str1;
    m++;
    str1 = str.replace(l, 1, str, l-3, 1);
    str1 = str1.replace(l-3, 1, 1, '0');
    res[m] = str1;
    m++;
    break;
    //4*4の場合
    /* href="switch(k) {
		case 0:
			str1   = str.replace(k, 1, str, k+3, 1);
			str1   = str1.replace(k+3, 1, 1, '0');
			res[n] = str1;
			n++;
			str1   = str.replace(k, 1, str, k+1, 1);
			str1   = str1.replace(k+1, 1, 1, '0');
			res[n] = str1;
			n++;
			break;
		case 1:
			str1   = str.replace(k, 1, str, k+3, 1);
			str1   = str1.replace(k+3, 1, 1, '0');
			res[n] = str1;
			n++;
			str1   = str.replace(k, 1, str, k-1, 1);
			str1   = str1.replace(k-1, 1, 1, '0');
			res[n] = str1;
			n++;
			str1   = str.replace(k, 1, str, k+1, 1);
			str1   = str1.replace(k+1, 1, 1, '0');
			res[n] = str1;
			n++;
			break;
		case 2:
			str1   = str.replace(k, 1, str, k+3, 1);
			str1   = str1.replace(k+3, 1, 1, '0');
			res[n] = str1;
			n++;
			str1   = str.replace(k, 1, str, k-1, 1);
			str1   = str1.replace(k-1, 1, 1, '0');
			res[n] = str1;
			n++;
			break;
		case 3:
			str1   = str.replace(k, 1, str, k-3, 1);
			str1   = str1.replace(k-3, 1, 1, '0');
			res[n] = str1;
			n++;
			str1   = str.replace(k, 1, str, k+3, 1);
			str1   = str1.replace(k+3, 1, 1, '0');
			res[n] = str1;
			n++;
			str1   = str.replace(k, 1, str, k+1, 1);
			str1   = str1.replace(k+1, 1, 1, '0');
			res[n] = str1;
			n++;
			break;
		case 4:
			str1   = str.replace(k, 1, str, k-3, 1);
			str1   = str1.replace(k-3, 1, 1, '0');
			res[n] = str1;
			n++;
			str1   = str.replace(k, 1, str, k+3, 1);
			str1   = str1.replace(k+3, 1, 1, '0');
			res[n] = str1;
			n++;
			str1   = str.replace(k, 1, str, k-1, 1);
			str1   = str1.replace(k-1, 1, 1, '0');
			res[n] = str1;
			n++;
			str1   = str.replace(k, 1, str, k+1, 1);
			str1   = str1.replace(k+1, 1, 1, '0');
			res[n] = str1;
			n++;
			break;
		case 5:
			str1   = str.replace(k, 1, str, k-3, 1);
			str1   = str1.replace(k-3, 1, 1, '0');
			res[n] = str1;
			n++;
			str1   = str.replace(k, 1, str, k+3, 1);
			str1   = str1.replace(k+3, 1, 1, '0');
			res[n] = str1;
			n++;
			str1   = str.replace(k, 1, str, k-1, 1);
			str1   = str1.replace(k-1, 1, 1, '0');
			res[n] = str1;
			n++;
			break;
		case 6:
			str1   = str.replace(k, 1, str, k-3, 1);
			str1   = str1.replace(k-3, 1, 1, '0');
			res[n] = str1;
			n++;
			str1   = str.replace(k, 1, str, k+1, 1);
			str1   = str1.replace(k+1, 1, 1, '0');
			res[n] = str1;
			n++;
			break;
		case 7:
			str1   = str.replace(k, 1, str, k-3, 1);
			str1   = str1.replace(k-3, 1, 1, '0');
			res[n] = str1;
			n++;
			str1   = str.replace(k, 1, str, k-1, 1);
			str1   = str1.replace(k-1, 1, 1, '0');
			res[n] = str1;
			n++;
			str1   = str.replace(k, 1, str, k+1, 1);
			str1   = str1.replace(k+1, 1, 1, '0');
			res[n] = str1;
			n++;
			break;
		case 8:
			str1   = str.replace(k, 1, str, k-3, 1);
			str1   = str1.replace(k-3, 1, 1, '0');
			res[n] = str1;
			n++;
			str1   = str.replace(k, 1, str, k-1, 1);
			str1   = str1.replace(k-1, 1, 1, '0');
			res[n] = str1;
			n++;
			break;"
     */
    
  }
  return m;
  
}

void width(string start, string goal)
{
  //for分で使用する変数
  int i1;
  int n;
  //計算量を求める際に使用する変数
  int fnode = 1;
  int snode = 0;
  //class Depthの変数
  int dep = 1;
  int ct = 1;
  //現在の状態
  string str;
  //移動後の状態
  string res[4];
  queue<pair<string, int> > q;
  map<string, Depth> ma;
  //イテレーション
  map<string, Depth>::iterator it;

  ma.insert(pair<string, Depth>(start, Depth("",dep)));
  q.push(pair<string, int>(start, dep));
  while(!q.empty())
    {
    str = q.front().first;
    dep = q.front().second;
    snode++;
    //ゴールの判定
    if(str == goal)
      {
      ct = dep;
      break;
    }
    //false
    //moveからのqueueに追加
    else{
      q.pop();
      n = move(str, res);
      for(i1 = 0; i1 < n; i1++)
        {
        it = ma.find(res[i1]);
    //状態が同等か判定
        if(it == ma.end())
          {
          ma.insert(pair<string, Depth>(res[i1], Depth(str, dep+1)));
          q.push(pair<string, int>(res[i1], dep+1));
          fnode++;
        }
      }

    }
  }

  //output
  while(str.length() > 0)
    {
    printf("\n  %c %c %c\n", str.at(0), str.at(1), str.at(2));
    printf("  %c %c %c\n", str.at(3), str.at(4), str.at(5));
    printf("  %c %c %c\n", str.at(6), str.at(7), str.at(8));
    //15パズルの場合は以下を適用
    //cout << str.at(0) << " " << str.at(1) << " " << str.at(2) << " " << str.at(3) << endl;                                      
    //cout << str.at(4) << " " << str.at(5) << " " << str.at(6) << " " << str.at(7) << endl;                                      
    //cout << str.at(8) << " " << str.at(9) << " " << str.at(10) << " " << str.at(11) << endl;                                    
    //cout << str.at(12) << " " << str.at(13) << " " << str.at(14) <<  " " << str.at(15) << endl;
    it = ma.find(str);
    str = ((*it).second).prev;
  }
}

void swap(int a, int b)
{
  int temp;
  temp = a;
  a = b;
  b = temp;
}

void permutation(vector <int> ve_data)
{
  //偶数置換と奇数置換のどちらかであるかを判定
  //授業中に実装したpermutationクラスを関数化して、ループ表示をする
  //これにより不可能な8パズルの問題提示を防ぐことができる
  int target;
  vector <bool> perm_check(MAX);
  counter = 0;
  cout << "置換をループで表示" << endl;
  for(int j = 0; j < MAX; j++)
    {
    if(!perm_check[j] && ve_data[j] != j)
      {
      int k =j;
      target = j;
      cout << "( "<< k <<" ";
      while(ve_data[k] != target)
        {
        perm_check[k] = true;
        k = ve_data[k];
        cout << k << " ";
        counter++;
      }
      perm_check[k] = true;
      cout << ")";
    }
    
  }
  cout << endl;
  //奇数置換は偶数置換に変換
  if(counter & 1)
    {//counter % 2 == 1 と一緒？
    cout << "諸事情により値の順番を変更します。" <<endl;
    //cout << endl;
    //    swap(ve_data[0], ve_data[1]);
    target = ve_data[0];
    ve_data[0] = ve_data[1];
    ve_data[1] = target;
    f = 1;
  }
  cout << "置換を考慮をした後の数列はこちらです" << endl;
  // cout << endl;
  for(int i = 0; i < MAX; i++){
    cout << ve_data[i] << " ";
  }
  cout << endl;
  if(counter > 0)
    {
    //いよいよパズルに値を入れる
    //視覚化
    cout << "8パズルの問題はこちらです。" << endl;
    //cout << endl;
    for(int y = 0; y < H; y++){
      for(int x = 0; x < W; x++){
        cout << setw(3) << (FPuzzle[y][x] = ve_data[y*H + x]);
      }
      cout << endl;
    }
    
  }
}

int main(void)
{
  
  srand((unsigned int)time(NULL));
  //  int counter;
  char numStr[1];
  string s;
  string goal = "123804765";
  //4*4の時はここもいじる
  vector <int> v_data(MAX);
  cout << "重複がないように0-8までの数を並べてください。" << endl;
  //cout<<endl;
  for(int i = 0; i < MAX; i++)
    {
    /*if(i == 0 && f == 1){
      cin >> v_data[1];
      sprintf(numStr, "%d", v_data[1]);
      s += string(numStr);
      cin >> v_data[0];
      sprintf(numStr, "%d", v_data[0]);
      s += string(numStr);
      i = 2;
      }*/
    //入力を求めたら置換した意味ないんじゃない？？
    cin >> v_data[i];
    sprintf(numStr, "%d", v_data[i]);
    s += string(numStr);
  }
  
  permutation(v_data);
  
  if(counter == 0)
    {
    cout << "与えられた数列では8パズルが作成できませんでした。" << endl;
    //cout << endl;
    cout << "もう一度、数列を0-8までの数で並べてください。" << endl;
    //cout << endl;
    for(int i = 0; i < MAX; i++)
      {
      s = "";
      /*if(i == 0 && f == 1){
      cin >> v_data[1];
      sprintf(numStr, "%d", v_data[1]);
      s += string(numStr);
      cin >> v_data[0];
      sprintf(numStr, "%d", v_data[0]);
      s += string(numStr);
      i = 2;
      }*/
      cin >> v_data[i];
      sprintf(numStr, "%d", v_data[i]);
      s += string(numStr);
      
    }
    
    permutation(v_data);
    
  }
  cout << "この問題に対して、あなたはこのように数字を動かすことでパズルを円滑に解くことができます。" << endl;
  if( f == 1)
    {
    //奇数置換だった場合にフラグを立て、フラグが立ったら以下の処理をするようにした
    //1番目の数と2番目の数を入れ替える
    s = "";
    //cin >> v_data[1];
    sprintf(numStr, "%d", v_data[1]);
      s += string(numStr);
      //cin >> v_data[0];
    sprintf(numStr, "%d", v_data[0]);
      s += string(numStr);
    for(int i = 2; i < MAX; i++){
      //cin >> v_data[i];
      sprintf(numStr, "%d", v_data[i]);
      s += string(numStr);
    }
    //cout << s << endl;
  }
  

  // cout << endl;
  cout << "チートフロー" << endl;
  width(s, goal);
  
  return 0;
}

