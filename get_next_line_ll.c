#include "get_next_line.c"

gnl	*initialize_fd(int fd, gnl *begin)
{	
	gnl	*result;
	gnl	*temp;

	temp = begin;
	result = (gnl*)malloc(sizeof(gnl));
	result->next = NULL;
	result->data = NULL;
	result->fd = fd;
	if (begin == NULL)
		*temp = result;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		*temp = result;
	}
	return (temp);
}

gnl	*check_fd(int fd, gnl *begin)
{
	gnl	*temp;

	temp = begin;
	if (temp != NULL)
	{
		while (temp->fd != fd)
			temp = temp->next;
	}
	return (temp);
}

int get_next_line(const int fd, char **line)
{
	static gnl	*begin;
	gnl		*temp;

	temp = check_fd(fd, begin);
	if (temp == NULL)
		temp = initialize_fd(fd, begin);
	else

	
}	
