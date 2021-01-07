Action()
{

	int i;
	char* s;
	
	web_url("computers", 
		"URL=http://computer-database.gatling.io/computers", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(7);
	

	web_reg_find("Text=Nothing to display",
	    "SaveCount=Param",	             
		LAST);
	

	web_submit_data("computers_2", 
		"Action=http://computer-database.gatling.io/computers", 
		"Method=GET", 
		"EncType=", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=f", "Value=homew", ENDITEM, 
		LAST);
	
		
		
		s = lr_eval_string("{Param}");
		i = atoi(s);

		
		if (i == 1) {
			
			lr_output_message("qqq");
	lr_think_time(5);

	web_url("Add a new computer", 
		"URL=http://computer-database.gatling.io/computers/new", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers?f=homew", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_data("computers_3", 
		"Action=http://computer-database.gatling.io/computers", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers/new", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=name", "Value=homew", ENDITEM, 
		"Name=introduced", "Value=2012-12-12", ENDITEM, 
		"Name=discontinued", "Value=2020-12-12", ENDITEM, 
		"Name=company", "Value=1", ENDITEM, 
		LAST);
	
	
		}

	return 0;
}