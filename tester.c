char	*strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		s1_len;

	if (!s1 || !s2)
		return (0);
	s1_len = strlen(s1);
	i = -1;
	if (!(res = (char*)malloc(sizeof(char) * (s1_len + strlen(s2) + 1))))
		return (0);
	while (s1[++i])
		res[i] = s1[i];
	i = -1;
	while (s2[++i])
		res[s1_len + i] = s2[i];
	res[s1_len + i] = 0;
	return (res);
}

int main(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		char *command = "./cub3d ";
		command = strjoin(command, av[i]);
		printf("%s\n", av[i]);
		system(command);
	}
}
