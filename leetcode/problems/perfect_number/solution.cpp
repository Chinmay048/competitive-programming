class Solution {
public:
   bool checkPerfectNumber(int num) {
  int flag=1;
  if(num==1) return false;
  for(int i=2;i<sqrt(num);i++)
    if(num%i==0)
      flag+=i+num/i;
  return (flag==num);
}
};