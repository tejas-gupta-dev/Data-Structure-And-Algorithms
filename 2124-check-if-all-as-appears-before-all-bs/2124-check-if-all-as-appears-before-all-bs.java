class Solution {
    public boolean checkString(String s) {
        int b=0;
        for(int j=0;j<s.length();j++){
            if(s.charAt(j)=='b'){
                b++;
            }
            else{
                if(b>0){
                    return false;
                }
            }
        }  
        return true;
    }
}