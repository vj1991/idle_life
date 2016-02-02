#define 		MAX_PL_NAME_LEN							40
#define			MAX_NUM_OF_PROFESSIONS					20


class player_business
{
	int								pl_id;
	int								business_level[MAX_NUM_OF_BUSINESS];

	void get_pl_business();
	void set_pl_business();
};

class player_professions
{
	int								pl_id;
	int								prof_level[MAX_NUM_OF_PROFESSIONS];

	void get_pl_professions();
	void set_pl_professions();
};

class player_info
{
	unsigned long int				pl_id;
	char 							pl_name[MAX_PL_NAME_LEN];

	float 							rating;
	float 							money;
	float 							income_per_sec;

	void get_pl_info();
	void set_pl_info();
};

class client_info
{
	int 							client_version;

	void get_cl_info();
	void set_pl_info();
};

class idle_life
{
	client_info 					cl_info;
	player_info 					pl_info;

	void get_main_info();
	void set_main_info();
};
