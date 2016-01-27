##归并排序     
merge函数：   
输入3个序号，计算两个数组的入口和长度。并将这个数组按从小到大的顺序合并成一个数组。
```  
merge(int start, int mid, int end)    
{   
   int n1 = mid - start + 1;
   int n2 = end - mid;
   int left[n1], right[n2];  //初始化两组数组
   int i, j, k;
   for (i = 0; i < n1; i++) /* 将sort函数分配的前一个数组存入 */
   left[i] = a[start+i];
   for (j = 0; j < n2; j++) /* 将sort函数分配的后一个数组存入 */
   right[j] = a[mid+1+j];
   i = j = 0;
   k = start;
   while (i < n1 && j < n2) //对两个数组进行排序融合，由于之前的底层数组都merge过，单个数组本身已经按从小到大顺序排列
	if (left[i] < right[j]) //数字较小的排在前面，同时该组的指针向后以以为再进行比较
	   a[k++] = left[i++];  
	else
	   a[k++] = right[j++];
   //像数组补充遗留的最大值
   while (i < n1) /* left[] is not exhausted */
   a[k++] = left[i++];
   while (j < n2) /* right[] is not exhausted */
   a[k++] = right[j++];
}    
```  
sort函数：将一个连续的数组**持续地**从中间分成两部分，并执行merge函数。直到不能再分    
 ```
sort(int start, int end)   
{   
	int mid;
	if (start < end) {
		mid = (start + end) / 2;
		printf("sort (%d-%d, %d-%d) %d %d %d %d %d
		%d %d %d\n",
		start, mid, mid+1, end,
		a[0], a[1], a[2], a[3], a[4], a[5],
		a[6], a[7]);
		sort(start, mid);
		sort(mid+1, end);
		merge(start, mid, end);
		printf("merge (%d-%d, %d-%d) to %d %d %d
		%d %d %d %d %d\n",
		start, mid, mid+1, end,
		a[0], a[1], a[2], a[3], a[4], a[5],
		a[6], a[7]);
	}
}
```    
