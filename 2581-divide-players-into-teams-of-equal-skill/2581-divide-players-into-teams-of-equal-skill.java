class Solution {
    public long dividePlayers(int[] skill) {
        if(skill.length==2){
            return skill[0]*skill[1];
        }
        Arrays.sort(skill);
        int sum=skill[0]+skill[skill.length-1];
        long ans=skill[0]*skill[skill.length-1];
        for(int i=1;i<skill.length/2;i++){
            int temp=skill[i]+skill[skill.length-1-i];
            if(temp==sum){
                ans+=skill[i]*skill[skill.length-i-1];
            }
            else{
                ans=0;
                break;
            }
        }
        if(ans==0){
            return -1;
        }
        return ans;
    }
}
