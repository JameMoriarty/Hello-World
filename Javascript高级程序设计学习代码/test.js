function longestConsec(strarr, k) {
    var biggest=0;
    var pos=0,num=0;
    //var ans = new Array();
    var ans="";
    if(strarr.length==0 || k>strarr.length || k<=0)
      return "";
    else{
      for(var i=0;i<strarr.length;i++){
        if(biggest<strarr[i].length){
          biggest=strarr[i].length;
          pos=i;
          //ans[0]=strarr[i];
          ans=strarr[i];
          console.log(pos);
        }
      }
      //console.log(pos);
      var j=pos-1,v=pos+1;
      while(num<k-1){
        if(j>=0&&strarr[j].length>strarr[k].length){
          //ans.unshift(strarr[j]);
          ans=strarr[j]+ans;
          console.log(strarr[j]);
          j--;
          num++;
        }
        else if(v<=strarr.length){
          //ans.push(strarr[v]);
          ans=ans+strarr[v];
          console.log(strarr[v]);
          v++;
          num++;
        }
      }
      console.log(ans);
    }
}
var strarr=["zone", "abigail", "theta", "form", "libe", "zas"];
longestConsec(strarr, 2);
//console.log(strarr[0].length);