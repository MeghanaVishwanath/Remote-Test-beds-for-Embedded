#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>

pthread_mutex_t lock;

void* threadFunc(void* arg){
	int id = (intptr_t)arg;
	//userCodes has name of code: "simple"
	pthread_mutex_lock(&lock);
	//filename = userCodes
	//extension = 1
	//userCode = userCodes1
	char* filename = "userCodes";
	char extension[10];
	sprintf(extension, "%d", id);
	char* idptr = extension;
	int size = strlen(filename) + strlen(idptr) + 1;
	char* userCode = (char*)malloc(sizeof(size));

	//userCodes1
	strcpy(userCode, filename);
	strcat(userCode, idptr);
	FILE* fptr;
	fptr = fopen(userCode, "r");
	char buffer[300];
	fscanf(fptr, "%s", buffer);

	char actuator[100];
    fscanf(fptr, "%s", actuator);

    char emailAddr[100];
	fscanf(fptr, "%s", emailAddr);

	char* ptr = buffer;
		//Sensor:first,second
	while(*ptr!=':'){
		ptr++;
	}
	ptr++;
	char* newPtr = (char*)malloc(strlen(buffer)+1);
	char* newString = newPtr;
	while(*ptr != '\0'){
		if(*ptr != ' '){
			*newPtr = *ptr;
			newPtr++;
		}
		ptr++;
	}
	*newPtr = '\0';
	int i=0;
	char Sensors[100];
	while(*newString!='\0'){
		Sensors[i] = *newString;
		newString++;
		i++;
	}
	Sensors[i] = '\0';
	// printf("%s\n", Sensors);
	char sensorNames[3][300];
	int k=0;
	int numOfSensor = 0;
	char* token = strtok(Sensors, ",");
	while( token != NULL ) {
		numOfSensor++;
		strcpy(sensorNames[k], token);
		// printf( " %s\n", token ); //printing each token
		token = strtok(NULL, ",");
		k++;
    }
    newPtr = NULL;
    newString = NULL;

	if(strlen(Sensors) != 0){
		
	 //    char emailAddr[100];
		// fscanf(fptr, "%s", emailAddr);
	    if(strlen(emailAddr) != 0){
	    	// printf("Going here.\n");
	    	for(int i=0; i<numOfSensor; i++){
	        	// printf("Sensor %d: %s",i+1, sensorNames[i]);
	        	// printf("\n");
	        	//email ID
	    		
	    		//printf("Email addr: %s\n", emailAddr);
	    
	    		//userFileEX = simple1
	    		char* userFileEX = (char*)malloc(strlen(sensorNames[i])+strlen(extension)+1);
	    		strcpy(userFileEX, sensorNames[i]);
	    		strcat(userFileEX, extension);
	    
	    		//userFile = simple1.c
	    		char* userFile = (char*)malloc(strlen(userFileEX)+strlen(".c")+1);
	    		strcpy(userFile, userFileEX);
	    		strcat(userFile, ".c");
	    		//printf("%s\n", userFile);
	    
	    		//run this code with locks
	    		//pthread_mutex_lock(&lock);
	    		FILE* bashS;
	    		char* bashScript = (char*)malloc(strlen("binFile")+strlen(extension)+strlen(".sh"));
	    		strcpy(bashScript, "binFile");
	    		strcat(bashScript, extension);
	    		strcat(bashScript, ".sh");
	    		bashS = fopen(bashScript, "w+");
	    		char* command1 = "chmod 777 ";
	    		char* command2 = "chmod +x ";
	    		char* scriptC1 = (char*)malloc(strlen(bashScript)+strlen(command1)+1);
	    		strcpy(scriptC1, command1);
	    		strcat(scriptC1, bashScript);
	    		char* scriptC2 = (char*)malloc(strlen(bashScript)+strlen(command2)+1);
	    		strcpy(scriptC2, command2);
	    		strcat(scriptC2, bashScript);
	    		system(scriptC1);
	    		system(scriptC2);
	    		char* sensorNameTxt = (char*)malloc(strlen(sensorNames[i])+1);
	    		strcpy(sensorNameTxt, sensorNames[i]);
	    		strcat(sensorNameTxt, ".txt");
	    		//create a bash script
	    		fprintf(bashS, "%s\n", "#!/bin/bash");
	    		fprintf(bashS, "\n%s %s %s %s\n", "gcc", userFile, "-o", userFileEX);
		 		fprintf(bashS, "%s%s %s%s\n", "./", userFileEX, " >> ",sensorNameTxt);
	    		fclose(bashS);
	    		//pthread_mutex_unlock(&lock);
	    		char* execCode = (char*)malloc(strlen(bashScript)+strlen("./")+1);
	    		strcpy(execCode, "./");
	    		strcat(execCode, bashScript);
	    		system(execCode);
	    		//python3 emailSend.py emailAddr userCodes1.txt
	    		char* commandToCode = (char*)malloc(strlen("python3 emailSend.py ")+strlen(emailAddr)+strlen(" ")+strlen(sensorNames[i])+strlen(".txt")+1);
	    		strcpy(commandToCode, "python3 emailSend.py ");
	    		strcat(commandToCode, emailAddr);
	    		strcat(commandToCode, " ");
	    		strcat(commandToCode, sensorNames[i]);
	    		strcat(commandToCode, ".txt");
	    		//printf("%s\n", commandToCode);	
	    		system(commandToCode);
	    		//system("python3 email_send.py");
	    		char* rem = (char*)malloc(strlen(bashScript)+strlen("rm ")+1);
	    		strcpy(rem, "rm ");
	    		strcat(rem, bashScript);
	    		system(rem);
	    		rem = NULL;
	    		rem = (char*)malloc(strlen(userFile)+strlen("rm ")+1);
	    		strcpy(rem, "rm ");
	    		strcat(rem, userFile);
	    		//printf("%s\n", rem);
	    		system(rem);
	    		rem = NULL;
	    		rem = (char*)malloc(strlen(userFile)+strlen("rm ")+1);
	    		strcpy(rem, "rm ");
	    		strcat(rem, userFileEX);
	    		system(rem);
	    		rem = NULL;
	    		rem = (char*)malloc(strlen(sensorNameTxt)+strlen("rm ")+1);
	    		strcpy(rem, "rm ");
	    		strcat(rem, sensorNameTxt);
	    		system(rem);
	    		//pthread_mutex_unlock(&lock);
	    
	    		//close all pointers
	    		// fclose(fptr);
	    		bashScript = NULL;
	    		// filename = NULL;
	    		// idptr = NULL;
	    		userFile = NULL;
	    		command1 = NULL;
	    		command2 = NULL;
	    		scriptC1 = NULL;
	    		scriptC2 = NULL;
	    		free(bashScript);
	    		// free(filename);
	    		// free(idptr);
	    		free(userFile);
	    		free(command1);
	    		free(command2);
	    		free(scriptC1);
	    		free(scriptC2);
	    		free(execCode);
	    		free(rem);
	        }

	        fclose(fptr);

	    }
	    else{
	    	printf("Email id not found.\n");
	    	// pthread_mutex_unlock(&lock);
	    	// return 0;
	    }


	}
	else{
		printf("Sensor files not found.\n");
		// pthread_mutex_unlock(&lock);
		// return 0;
	}

	//check for PWM files
	char* ptrA = actuator;
		//Sensor:first,second
	while(*ptrA!=':'){
		ptrA++;
	}
	ptrA++;
	char* newPtrA = (char*)malloc(strlen(actuator)+1);
	char* newStringA = newPtrA;
	while(*ptrA != '\0'){
		if(*ptrA != ' '){
			*newPtrA = *ptrA;
			newPtrA++;
		}
		ptrA++;
	}
	*newPtrA = '\0';
	i=0;
	char Actuators[100];
	while(*newStringA!='\0'){
		Actuators[i] = *newStringA;
		newStringA++;
		i++;
	}
	Actuators[i] = '\0';
	// printf("%s\n", Actuators);
	char actuatorNames[2][300];
	k=0;
	int numOfAc = 0;
	char* tokenAC = strtok(Actuators, ",");
	while( tokenAC != NULL ) {
		numOfAc++;
		strcpy(actuatorNames[k], tokenAC);
		// printf( " %s\n", token ); //printing each token
		tokenAC = strtok(NULL, ",");
		k++;
    }
    newPtrA = NULL;
    newStringA = NULL;
    if(strlen(Actuators) != 0){
    	//light1.py
    	if(strlen(emailAddr)!=0){
    		
    		for(int i=0; i<numOfAc; i++){

    			char* acName = (char*)malloc(strlen(actuatorNames[i])+strlen(idptr)+1);
    			strcpy(acName, actuatorNames[i]);
    			strcat(acName, extension);
    			
    			// printf("%s\n", acName);
    			// //compile using python
    			// //python3 light1.py >> light1.txt
    			char* outputFile = (char*)malloc(strlen(acName)+strlen(".txt")+1);
    			strcpy(outputFile, acName);
    			strcat(outputFile, ".txt");

    			char* compileString = (char*)malloc(strlen("python3 ")+strlen(acName)+strlen(".py >> ")+strlen(outputFile)+1);
    			strcpy(compileString, "python3 ");
    			strcat(compileString, acName);
    			strcat(compileString, ".py >> ");
    			strcat(compileString, outputFile);
    			system(compileString);
    			// printf("%s\n", compileString);
    			//create the email string
    			// printf("%s\n", emailAddr);
    			// printf("%s\n", outputFile);
    			char* commandToCode = (char*)malloc(strlen("python3 emailSend.py ")+strlen(emailAddr)+strlen(" ")+strlen(outputFile)+1);   
    			strcpy(commandToCode, "python3 emailSend.py ");
    			strcat(commandToCode, emailAddr);
    			strcat(commandToCode, " ");
    			strcat(commandToCode, outputFile);
    			// printf("%s\n", commandToCode);
    			system(commandToCode);
    			char* rem = (char*)malloc(strlen(outputFile)+strlen("rm ")+1);
	    		strcpy(rem, "rm ");
	    		strcat(rem, outputFile);
	    		system(rem);
	    		outputFile = NULL;
	    		free(outputFile);	
	    		commandToCode = NULL;
	    		free(commandToCode);
    		}    		
    	}
    }

	pthread_mutex_unlock(&lock);
	return 0;
}

int main(){
	pthread_t user1, user2;
	int i=1;
	pthread_create(&user1, NULL, threadFunc, (void*)(intptr_t)i);
	i++;
	pthread_create(&user2, NULL, threadFunc, (void*)(intptr_t)i);
	i++;
	pthread_join(user1, NULL);
	pthread_join(user2, NULL);
	return 0;
}
