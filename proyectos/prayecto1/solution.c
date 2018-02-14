#include <cstdio>
#include <cstring>

#define MAX_X 32001 

int main(){
	int N,x,y;
	scanf("%d",&N);
	
	int ans[N];
	memset(ans,0,sizeof(ans));
	memset(T,0,sizeof(T));
	
	for(int i = 0;i<N;++i){
		scanf("%d %d",&x,&y);
		++ans[F(x+1)];
		update(x+1,1);
	}
	
	for(int i = 0;i<N;++i)
		printf("%d\n",ans[i]);
	
	return 0;
}