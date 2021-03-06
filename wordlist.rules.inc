<?php

/**
 * @file
 * Rules conditions for the Word list module.
 */


/**
 * Implements hook_rules_condition_info().
 */
function wordlist_rules_condition_info() {
	$conditions = array(
		'wordlist_condition_words_in_text' => array(
			'label' => t('Any of words is in text'),
			'parameter' => array(
				'long_text' => array(
					'label' => t('Text to investigate'), 
					'type' => 'text'
				),
				'list_of_words' => array(
					'label' => t('List of words'), 
					'type' => 'list<text>'
				),
			),
			'group' => t('Rules'),
		),
	);

	return $conditions;
}


/**
 * The condition callback for wordlist_condition_words_in_text.
 */
function wordlist_condition_words_in_text($long_text, $list_of_words) {
	// Loop through all the given words, return TRUE if the word is found.
	foreach ($list_of_words as $word) {
		if (stristr($long_text, $word)) {
			return TRUE;
		}
	}

	// If we've gotten this far, none of the words are present. Return FALSE.
	return FALSE;
}