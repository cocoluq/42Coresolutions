/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luqli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:50:08 by luqli             #+#    #+#             */
/*   Updated: 2023/10/23 12:50:35 by luqli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_split_words(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
		{
			i++;
		}
		if (s[i] != c && s[i])
		{
			words++;
			i++;
			while (s[i] != c && s[i])
			{
				i++;
			}
		}
	}
	return (words);
}

static int	check_array(char **array, char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
		return (0);
	}
	return (1);
}

static size_t	allocate_str(char const *s, char c)
{
	size_t	len;

	len = 0;
	if (!ft_strchr(s, c))
		len = ft_strlen(s);
	else
		len = ft_strchr(s, c) - s;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	len;
	size_t	i;

	i = 0;
	array = (char **)malloc(sizeof(char *) * (count_split_words(s, c) + 1));
	if (!array)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			len = allocate_str(s, c);
			array[i] = ft_substr(s, 0, len);
			if (!check_array(array, array[i++]))
				return (NULL);
			s += len;
		}
	}
	array[i] = NULL;
	return (array);
}

/* int main()
{
    // Test 1: Basic test with a single delimiter
    char *test_string1 = "apple,banana,cherry,";
    char delimiter1 = ',';
    char **result1 = ft_split(test_string1, delimiter1);

    printf("Test 1:\n");
    for (int i = 0; result1[i] != NULL; i++)
    {
        printf("%s\n", result1[i]);
        free(result1[i]);
    }
    free(result1);

    // Test 2: Handling multiple consecutive delimiters
    char *test_string2 = "apple,,banana,,cherry";
    char delimiter2 = ',';
    char **result2 = ft_split(test_string2, delimiter2);

    printf("\nTest 2:\n");
    for (int i = 0; result2[i] != NULL; i++)
    {
        printf("%s\n", result2[i]);
        free(result2[i]);
    }
    free(result2);

    // Test 3: Handling a string with no delimiters
    char *test_string3 = "onetwothree";
    char delimiter3 = ',';
    char **result3 = ft_split(test_string3, delimiter3);

    printf("\nTest 3:\n");
    for (int i = 0; result3[i] != NULL; i++)
    {
        printf("%s\n", result3[i]);
        free(result3[i]);
    }
    free(result3);

    // Test 4: Handling an empty string
    char *test_string4 = "";
    char delimiter4 = ',';
    char **result4 = ft_split(test_string4, delimiter4);

    printf("\nTest 4:\n");
    for (int i = 0; result4[i] != NULL; i++)
    {
        printf("%s\n", result4[i]);
        free(result4[i]);
    }
    free(result4);

    return 0;
} */