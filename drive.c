/******************************************************************************
** Student name: 	...
** Student number: 	...
** Course: 			Advanced Programming Techniques - S2 2018
******************************************************************************/

#include "drive.h"
#include "invector.h"
#include "pop.h"
#include "gene.h"

int main(int argc, char *argv[])
{
	FILE * fp;
	InVTable invt;
	Pop_list * list;
	int i, numAlleles, popSize, populationSize;

	/* The only point at which srand should be called */
	srand(SRAND_SEED);

	if(argc != CMD_ARG_MAX)
	{
		printf("Incorrect number of arguments. \n\n");
		return EXIT_FAILURE;
	}

	fp = fopen(argv[inputFile], "r");
	if(fp == NULL)
	{
		printf("Unable to open file. \n\n");
		return EXIT_FAILURE;
	}

	fclose(fp);

	printInvector(&invt);
	printf("\n");

	#ifdef DEBUG
	test_minfn();
	test_pcbmill();
	#else
	printf("Not DEBUG \n");

	pop_init(&list);

	if(strcmp(argv[geneType], "minfn") == 0)
	{
		pop_set_fns(list, create_minfn_chrom, mutate_minfn, crossover_minfn, eval_minfn);
	}
	else if(strcmp(argv[geneType], "pcbmill") == 0)
	{
		pop_set_fns(list, create_pcbmill_chrom, mutate_pcbmill, crossover_pcbmill, eval_pcbmill);
	}
	else
	{
		printf("Unknown gene type. \n\n");
		return EXIT_FAILURE;
	}

	exit(EXIT_FAILURE);

	numAlleles = strtol(argv[numAlleles], NULL, 10);
	populationSize = strtol(argv[popSize], NULL, 10);
	for (i =0; i < populationSize; i++)
	{
		insertNode(list, numAlleles);
	}

	printList(list);

	return EXIT_SUCCESS;
	#endif

}

void test_minfn(void){
	/* TO DO */
	Gene * gene = gene_create_rand_gene(TEST_ALLELE_LEN, create_minfn_chrom);
	Gene * geneM = mutate_minfn(gene);
	Gene * gene1 = gene_create_rand_gene(TEST_ALLELE_LEN, create_minfn_chrom);
	Gene * gene2 = gene_create_rand_gene(TEST_ALLELE_LEN, create_minfn_chrom);
	Gene * gene3 = crossover_minfn(gene1, gene2);

	printf("MINFN gene:\n");
	/* TO DO - create a random minfn gene by calling create_rand_gene
	The length of the gene's chromosome should be TEST_ALLELE_LEN */
	/* TO DO - print the gene */
	gene_print(gene);

	printf("Mutate: ");
	/* TO DO - create a mutant copy of the gene using mutate_minfn */
	/* TO DO - print the mutant gene */
	printf("\n");
	gene_print(geneM);

	/* TO DO - free the original gene and the mutant */
	gene_free(gene);
	gene_free(geneM);

	printf("MINFN genes:\n");
	/* TO DO - create 2 random minfn 'parent' genes using calls
	to create_rand_gene
	The length of the gene's chromosome should be TEST_ALLELE_LEN */

	/* TO DO - print each gene */
	gene_print(gene1);
	gene_print(gene2);

	printf("Crossover:\n");
	/* TO DO produce a new gene by calling crossover_minfn
	with the parent genes */
	/* TO DO - print the new gene */
	gene_print(gene3);

	printf("\n");
	/* TO DO - free both parents and the child gene */
	gene_free(gene1);
	gene_free(gene2);
	gene_free(gene3);
}

void test_pcbmill(void){
	/* TO DO */
	Gene * gene = gene_create_rand_gene(TEST_ALLELE_LEN, create_pcbmill_chrom);
	Gene * geneM = mutate_pcbmill(gene);
	Gene * gene1 = gene_create_rand_gene(TEST_ALLELE_LEN, create_pcbmill_chrom);
	Gene * gene2 = gene_create_rand_gene(TEST_ALLELE_LEN, create_pcbmill_chrom);
	Gene * gene3 = crossover_pcbmill(gene1, gene2);


	printf("PCBMILL gene:\n");
	/* TO DO - create a random pcbmill gene by calling create_rand_gene
	The length of the gene's chromosome should be TEST_ALLELE_LEN */
	/* TO DO - print the gene using gene_print */
	gene_print(gene);

	printf("Mutate: ");
	/* TO DO - create a mutant copy of the gene using mutate_pcbmill */
	/* TO DO - print the mutant gene using gene_print */
	printf("\n");
	gene_print(geneM);
	/* TO DO - free the original gene and the mutant */
	gene_free(gene);
	gene_free(geneM);

	printf("PCBMILL genes:\n");
	/* TO DO - create 2 random pcbmill 'parent' genes using calls
	to create_rand_gene
	The length of the gene's chromosome should be TEST_ALLELE_LEN */

	/* TO DO - print each gene */
	gene_print(gene1);
	gene_print(gene2);

	printf("Crossover:\n");
	/* TO DO produce a new gene by calling crossover_pcbmill
	with the parent genes */
	/* TO DO - print the new gene */
	gene_print(gene3);

	printf("\n");
	/* TO DO - free both parents and the child gene */
	gene_free(gene1);
	gene_free(gene2);
	gene_free(gene3);

}
