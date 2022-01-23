while(i>=0 || j>= 0 || carry){
        if( i>=0){
            carry+= a[i] - '0';
            i--;
        }
        if(j>=0){
            carry+= a[j] - '0';
            j--;
        }
        ans+=(carry%2 + '0');
        carry = carry/2;
    }