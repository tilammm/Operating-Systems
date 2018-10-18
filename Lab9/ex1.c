#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct PageTable {
	int frame_number;
	bool valid;
}*PageTable;

struct FrameTable {
	int page_number;
	int counter;
}*FrameTable;

void AgeIncrease (int frames){
	int i;
	for (i=0;i<frames;i++){
		FrameTable[i].counter++;
	}
}

int OldestIndex (int frames){
	int oldest=-1;
	int i;
	int index;
	for (i=0;i<frames;i++){
		if (oldest<FrameTable[i].counter){
			oldest=FrameTable[i].counter;
			index=i;
		}
	}
	return index;
}

int main (int argc, char *argv[]){
	int pages = 1000;

	int frames;
	scanf("%d", &frames);

	struct PageTable PageTable[pages];
	struct FrameTable FrameTable [frames];

	int i;
	for (i=0;i<pages; i++){
		PageTable[i].valid=false;
	}

	for (i=0;i<frames;i++){
		FrameTable[i].counter=0;
	}

	FILE *fp=fopen("Lab 09 input.txt", "r");

	int request;
	int frame_table_counter=0;
	int page_fault_counter=0;
	int request_counter=0;
	int memory_ref_counter=0;
	while (!feof(fp)){
		fscanf(fp, "%d", &request);
		request_counter++;
		if (PageTable[request].valid==false){
			FrameTable[frame_table_counter].page_number=request;
			PageTable[request].valid=true;
			PageTable[request].frame_number=frame_table_counter;
			frame_table_counter++;
			page_fault_counter++;
			memory_ref_counter++;
		}

		if (request_counter==1000){
			FILE *fp=fopen("Lab 09 input.txt", "a");
			fprintf (fp, "%d\n", memory_ref_counter);
			memory_ref_counter=0;
			request_counter=0;
			fclose(fp);
		}
		if (frame_table_counter==frames){
			break;
		}

	}


	while (!feof(fp)){
		fscanf(fp, "%d", &request);
		request_counter++;
		AgeIncrease(frames);
		if (PageTable[request].valid==false){
			int oldest_page=OldestIndex(frames);
			PageTable[FrameTable[oldest_page].page_number].valid=false;
			FrameTable[oldest_page].page_number=request;
			FrameTable[oldest_page].counter=0;
			PageTable[request].frame_number=oldest_page;
			PageTable[request].valid=true;
			page_fault_counter++;
			memory_ref_counter++;
		}

		if (request_counter==1000){
			FILE *fp=fopen("Lab 09 input.txt", "a");
			fprintf (fp, "%d\n", memory_ref_counter);
			memory_ref_counter=0;
			request_counter=0;
			fclose(fp);
		}
	}

	printf("Total page faults %d\n", page_fault_counter);

	fclose(fp);
	return 0;
}