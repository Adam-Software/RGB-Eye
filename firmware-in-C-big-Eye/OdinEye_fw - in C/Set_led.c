void set_color(uint8_t color, uint8_t state){
	switch (color){
		case RED :{
			switch (state) {
				case ON:{//U1_registers[5] = U1_registers[5] | 0b00000100;
					U1_registers[5] |= (1<<RED);
				break;}
				case OFF:{
					//U1_registers[5] = U1_registers[5] & 0b11111011;
					U1_registers[5] &=~ (1<<RED);
				break;}
			}
			break;
		}
		case GREEN :{
			switch (state) {
				case ON:{
					//U1_registers[5] = U1_registers[5] | 0b00001000;
					U1_registers[5] |= (1<<GREEN);
				break;}
				case OFF:{
					//U1_registers[5] = U1_registers[5] & 0b11110111;
					U1_registers[5] &=~ (1<<GREEN);
				break;}
			}
			break;
		}
		case BLUE :{
			switch (state) {
				case ON:{
					//U1_registers[5] = U1_registers[5] | 0b00010000;
					U1_registers[5] |= (1<<BLUE);
				break;}
				case OFF:{
					//U1_registers[5] = U1_registers[5] & 0b11101111;
					U1_registers[5] &=~ (1<<BLUE);
				break;}
			}
			break;
		}
		
		case RB_COLOR :{
			switch (state) {
				case ON:{
						U1_registers[5] |= (1<<BLUE)|(1<<RED);
				break;}
				case OFF:{
						U1_registers[5] &=~ (1<<BLUE)|(1<<RED);
				break;}
			}
			break;
		}
		
		case RG_COLOR :{
			switch (state) {
				case ON:{
						U1_registers[5] |= (1<<RED)|(1<<GREEN);
				break;}
				case OFF:{
						U1_registers[5] &=~ (1<<RED)|(1<<GREEN);
				break;}
			}
			break;
		}		
		
		case BG_COLOR :{
			switch (state) {
				case ON:{
						U1_registers[5] |= (1<<BLUE)|(1<<GREEN);
				break;}
				case OFF:{
						U1_registers[5] &=~ (1<<BLUE)|(1<<GREEN);
				break;}
			}
			break;
		}
				case RGB_COLOR :{
					switch (state) {
						case ON:{
						U1_registers[5] |= (1<<BLUE)|(1<<GREEN)|(1<<RED);
						break;}
						case OFF:{
						U1_registers[5] &=~ (1<<BLUE)|(1<<GREEN)|(1<<RED);
						break;}
					}
					break;
				}
		default:
		break;
	}
}
//**************for small version*************************

// void set_color(uint8_t color, uint8_t state){
// 	switch (color){
// 		case RED :{
// 			switch (state) {
// 				case ON:{U1_registers[5] = U1_registers[5] | 0b00011000;
// 				break;}
// 				case OFF:{U1_registers[5] = U1_registers[5] &  0b00011000;
// 				break;}
// 			}
// 			break;
// 		}
// 		case GREEN :{
// 			switch (state) {
// 				case ON:{U1_registers[5] = U1_registers[5] | 0b00010100;
// 				break;}
// 				case OFF:{U1_registers[5] = U1_registers[5] & 0b00101000;
// 				break;}
// 			}
// 			break;
// 		}
// 		case BLUE :{
// 			switch (state) {
// 				case ON:{U1_registers[5] = U1_registers[5] | 0b00001100;
// 				break;}
// 				case OFF:{U1_registers[5] = U1_registers[5] & 0b00001100;
// 				break;}
// 			}
// 			break;
// 		}
// 		default:
// 		break;
// 	}
// }




void set_led(uint8_t led, uint8_t state){
	if (led <0)
	{led = led+80;
	}
	if (led >80)
	{led = led-80;
	}
	if (led>160){
		led = 1;
	}

	
	
	switch (led){
		
		case 1: {
			switch (state){
				case OFF: {
					U2_registers[4] = U2_registers[4] & 0b11110111;
				break;}
				case ON:{
					U2_registers[4] = U2_registers[4] | 0b00001000;
				break;}}
				break;
			}
			case 2: {
				switch (state){
					case OFF: {
						U2_registers[3] = U2_registers[3] & 0b01111111;
					break;}
					case ON:{
						U2_registers[3] = U2_registers[3] | 0b10000000;
					break;}}
					break;
				}
				
				case 3: {
					switch (state){
						case OFF: {
							U2_registers[3] = U2_registers[3] & 0b11110111;
						break;}
						case ON:{
							U2_registers[3] = U2_registers[3] | 0b00001000;
						break;}}
						break;
					}
					
					case 4: {
						switch (state){
							case OFF: {
								U2_registers[2] = U2_registers[2] & 0b01111111;
							break;}
							case ON:{
								U2_registers[2] = U2_registers[2] | 0b10000000;
							break;}}
							break;
						}

						case 5: {
							switch (state){
								case OFF: {
									U2_registers[4] = U2_registers[4] & 0b11111011;
								break;}
								case ON:{
									U2_registers[4] = U2_registers[4] | 0b00000100;
								break;}}
								break;
							}
							case 6: {
								switch (state){
									case OFF: {
										U2_registers[3] = U2_registers[3] & 0b10111111;
									break;}
									case ON:{
										U2_registers[3] = U2_registers[3] | 0b01000000;
									break;}}
									break;
								}

								case 7	: {
									switch (state){
										case OFF: {
											U2_registers[3] = U2_registers[3] & 0b11111011;
										break;}
										case ON:{
											U2_registers[3] = U2_registers[3] | 0b00000100;
										break;}}
										break;
									}

									case 8	: {
										switch (state){
											case OFF: {
												U2_registers[2] = U2_registers[2] & 0b10111111;
											break;}
											case ON:{
												U2_registers[2] = U2_registers[2] | 0b01000000;
											break;}}
											break;
										}

										case 9	: {
											switch (state){
												case OFF: {
													U2_registers[4] = U2_registers[4] & 0b11111101;
												break;}
												case ON:{
													U2_registers[4] = U2_registers[4] | 0b00000010;
												break;}}
												break;
											}
											
											case 10	: {
												switch (state){
													case OFF: {
														U2_registers[3] = U2_registers[3] & 0b11011111;
													break;}
													case ON:{
														U2_registers[3] = U2_registers[3] | 0b00100000;
													break;}}
													break;
												}
												
												case 11	: {
													switch (state){
														case OFF: {
															U2_registers[3] = U2_registers[3] & 0b11111101;
														break;}
														case ON:{
															U2_registers[3] = U2_registers[3] | 0b00000010;
														break;}}
														break;
													}
													
													case 12	: {
														switch (state){
															case OFF: {
																U2_registers[2] = U2_registers[2] & 0b11011111;
															break;}
															case ON:{
																U2_registers[2] = U2_registers[2] | 0b00100000;
															break;}}
															break;
														}
														
														case 13	: {
															switch (state){
																case OFF: {
																	U2_registers[4] = U2_registers[4] & 0b11111110;
																break;}
																case ON:{
																	U2_registers[4] = U2_registers[4] | 0b00000001;
																break;}}
																break;
															}
															
															case 14	: {
																switch (state){
																	case OFF: {
																		U2_registers[3] = U2_registers[3] & 0b11101111;
																	break;}
																	case ON:{
																		U2_registers[3] = U2_registers[3] | 0b00010000;
																	break;}}
																	break;
																}

																case 15	: {
																	switch (state){
																		case OFF: {
																			U2_registers[3] = U2_registers[3] & 0b11111110;
																		break;}
																		case ON:{
																			U2_registers[3] = U2_registers[3] | 0b00000001;
																		break;}}
																		break;
																	}
																	case 16	: {
																		switch (state){
																			case OFF: {
																				U2_registers[2] = U2_registers[2] & 0b11101111;
																			break;}
																			case ON:{
																				U2_registers[2] = U2_registers[2] | 0b00010000;
																			break;}}
																			break;
																		}
																		
																		case 17	: {
																			switch (state){
																				case OFF: {
																					U2_registers[2] = U2_registers[2] & 0b11111101;
																				break;}
																				case ON:{
																					U2_registers[2] = U2_registers[2] | 0b00000010;
																				break;}}
																				break;
																			}
																			case 18	: {

																				switch (state){
																					case OFF: {
																						U2_registers[2] = U2_registers[2] & 0b11111110;
																					break;}
																					case ON:{
																						U2_registers[2] = U2_registers[2] | 0b00000001;
																					break;}}
																					break;
																				}
																				
																				case 19	: {
																					switch (state){
																						case OFF: {
																							U2_registers[1] = U2_registers[1] & 0b01111111;
																						break;}
																						case ON:{
																							U2_registers[1] = U2_registers[1] | 0b10000000;
																						break;}}
																						break;
																					}
																					
																					case 20	: {
																						switch (state){
																							case OFF: {
																								U2_registers[1] = U2_registers[1] & 0b10111111;
																							break;}
																							case ON:{
																								U2_registers[1] = U2_registers[1] | 0b01000000;
																							break;}}
																							break;
																						}
																						case 21	: {
																							switch (state){
																								case OFF: {
																									U2_registers[1] = U2_registers[1] & 0b11111011;
																								break;}
																								case ON:{
																									U2_registers[1] = U2_registers[1] | 0b00000100;
																								break;}}
																								break;
																							}
																							case 22	: {

																								switch (state){
																									case OFF: {
																										U2_registers[1] = U2_registers[1] & 0b11110111;
																									break;}
																									case ON:{
																										U2_registers[1] = U2_registers[1] | 0b00001000;
																									break;}}
																									break;
																								}
																								
																								case 23	: {
																									switch (state){
																										case OFF: {
																											U2_registers[1] = U2_registers[1] & 0b11101111;
																										break;}
																										case ON:{
																											U2_registers[1] = U2_registers[1] | 0b00010000;
																										break;}}
																										break;
																									}
																									
																									case 24	: {
																										switch (state){
																											case OFF: {
																												U2_registers[1] = U2_registers[1] & 0b11011111;
																											break;}
																											case ON:{
																												U2_registers[1] = U2_registers[1] | 0b00100000;
																											break;}}
																											break;
																										}
																										case 25	: {
																											switch (state){
																												case OFF: {
																													U2_registers[0] = U2_registers[0] & 0b11110111;
																												break;}
																												case ON:{
																													U2_registers[0] = U2_registers[0] | 0b00001000;
																												break;}}
																												break;
																											}
																											case 26	: {
																												switch (state){
																													case OFF: {
																														U2_registers[0] = U2_registers[0] & 0b11111011;
																													break;}
																													case ON:{
																														U2_registers[0] = U2_registers[0] | 0b00000100;
																													break;}}
																													break;
																												}
																												case 27	: {
																													switch (state){
																														case OFF: {
																															U2_registers[0] = U2_registers[0] & 0b11111101;
																														break;}
																														case ON:{
																															U2_registers[0] = U2_registers[0] | 0b00000010;
																														break;}}
																														break;
																													}
																													case 28	: {
																														switch (state){
																															case OFF: {
																																U2_registers[0] = U2_registers[0] & 0b11111110;
																															break;}
																															case ON:{
																																U2_registers[0] = U2_registers[0] | 0b00000001;
																															break;}}
																															break;
																														}
																														
																														case 29	: {
																															switch (state){
																																case OFF: {
																																	U2_registers[4] = U2_registers[4] & 0b10111111;
																																break;}
																																case ON:{
																																	U2_registers[4] = U2_registers[4] | 0b01000000;
																																break;}}
																																break;
																															}
																															
																															case 30	: {
																																switch (state){
																																	case OFF: {
																																		U2_registers[5] = U2_registers[5] & 0b11111101;
																																	break;}
																																	case ON:{
																																		U2_registers[5] = U2_registers[5] | 0b00000010;
																																	break;}}
																																	break;
																																}
																																
																																case 31	: {
																																	switch (state){
																																		case OFF: {
																																			U2_registers[5] = U2_registers[5] & 0b11101111;
																																		break;}
																																		case ON:{
																																			U2_registers[5] = U2_registers[5] | 0b00010000;
																																		break;}}
																																		break;
																																	}
																																	
																																	case 32	: {
																																		switch (state){
																																			case OFF: {
																																				U2_registers[5] = U2_registers[5] & 0b01111111;
																																			break;}
																																			case ON:{
																																				U2_registers[5] = U2_registers[5] | 0b10000000;
																																			break;}}
																																			break;
																																		}
																																		
																																		case 33	: {
																																			switch (state){
																																				case OFF: {
																																					U2_registers[4] = U2_registers[4] & 0b11011111;
																																				break;}
																																				case ON:{
																																					U2_registers[4] = U2_registers[4] | 0b00100000;
																																				break;}}
																																				break;
																																			}
																																			
																																			case 34	: {
																																				switch (state){
																																					case OFF: {
																																						U2_registers[5] = U2_registers[5] & 0b11111110;
																																					break;}
																																					case ON:{
																																						U2_registers[5] = U2_registers[5] | 0b00000001;
																																					break;}}
																																					break;
																																				}
																																				
																																				case 35	: {
																																					switch (state){
																																						case OFF: {
																																							U2_registers[5] = U2_registers[5] & 0b11110111;
																																						break;}
																																						case ON:{
																																							U2_registers[5] = U2_registers[5] | 0b00001000;
																																						break;}}
																																						break;
																																					}
																																					
																																					case 36	: {
																																						switch (state){
																																							case OFF: {
																																								U2_registers[5] = U2_registers[5] & 0b10111111;
																																							break;}
																																							case ON:{
																																								U2_registers[5] = U2_registers[5] | 0b01000000;
																																							break;}}
																																							break;
																																						}

																																						case 37	: {
																																							switch (state){
																																								case OFF: {
																																									U2_registers[4] = U2_registers[4] & 0b11101111;
																																								break;}
																																								case ON:{
																																									U2_registers[4] = U2_registers[4] | 0b00010000;
																																								break;}}
																																								break;
																																							}

																																							case 38	: {
																																								switch (state){
																																									case OFF: {
																																										U2_registers[4] = U2_registers[4] & 0b01111111;
																																									break;}
																																									case ON:{
																																										U2_registers[4] = U2_registers[4] | 0b10000000;
																																									break;}}
																																									break;
																																								}

																																								case 39	: {
																																									switch (state){
																																										case OFF: {
																																											U2_registers[5] = U2_registers[5] & 0b11111011;
																																										break;}
																																										case ON:{
																																											U2_registers[5] = U2_registers[5] | 0b00000100;
																																										break;}}
																																										break;
																																									}

																																									case 40	: {
																																										switch (state){
																																											case OFF: {
																																												U2_registers[5] = U2_registers[5] & 0b11011111;
																																											break;}
																																											case ON:{
																																												U2_registers[5] = U2_registers[5] | 0b00100000;
																																											break;}}
																																											break;
																																										}



case 41	: {
	switch (state){
		case OFF: {
			U1_registers[2] = U1_registers[2] & 0b01111111;
		break;}
		case ON:{
			U1_registers[2] = U1_registers[2] | 0b10000000;
		break;}}
		break;
	}


case 42	: {
	switch (state){
		case OFF: {
			U1_registers[2] = U1_registers[2] & 0b11110111;
		break;}
		case ON:{
			U1_registers[2] = U1_registers[2] | 0b00001000;
		break;}}
		break;
	}


case 43	: {
		switch (state){
			case OFF: {
				U1_registers[1] = U1_registers[1] & 0b01111111;
			break;}
			case ON:{
				U1_registers[1] = U1_registers[1] | 0b10000000;
			break;}}
			break;	
		
		
	}


case 44	: {

			switch (state){
				case OFF: {
					U1_registers[1] = U1_registers[1] & 0b11110111;
				break;}
				case ON:{
					U1_registers[1] = U1_registers[1] | 0b00001000;
				break;}}
				break;
	}
	
case 45	: {

						switch (state){
							case OFF: {
								U1_registers[2] = U1_registers[2] & 0b10111111;
							break;}
							case ON:{
								U1_registers[2] = U1_registers[2] | 0b01000000;
							break;}}
							break;
	}


	case 46	: {
					switch (state){
						case OFF: {
							U1_registers[2] = U1_registers[2] & 0b11111011;
						break;}
						case ON:{
							U1_registers[2] = U1_registers[2] | 0b00000100;
						break;}}
						break;

		}


		case 47	: {
		switch (state){
			case OFF: {
				U1_registers[1] = U1_registers[1] & 0b10111111;
			break;}
			case ON:{
				U1_registers[1] = U1_registers[1] | 0b01000000;
			break;}}
			break;
			}


			case 48	: {
	switch (state){
		case OFF: {
			U1_registers[1] = U1_registers[1] & 0b11111011;
		break;}
		case ON:{
			U1_registers[1] = U1_registers[1] | 0b00000100;
		break;}}
		break;
				} 
 
case 49	: {
				switch (state){
					case OFF: {
						U1_registers[2] = U1_registers[2] & 0b11011111;
					break;}
					case ON:{
						U1_registers[2] = U1_registers[2] | 0b00100000;
					break;}}
					break;
					
	}


	case 50	: {
			switch (state){
				case OFF: {
					U1_registers[2] = U1_registers[2] & 0b11111101;
				break;}
				case ON:{
					U1_registers[2] = U1_registers[2] | 0b00000010;
				break;}}
				break;
		}


		case 51	: {
						switch (state){
							case OFF: {
								U1_registers[1] = U1_registers[1] & 0b11011111;
							break;}
							case ON:{
								U1_registers[1] = U1_registers[1] | 0b00100000;
							break;}}
							break;
				
			}


			case 52	: {

						switch (state){
							case OFF: {
								U1_registers[1] = U1_registers[1] & 0b11111101;
							break;}
							case ON:{
								U1_registers[1] = U1_registers[1] | 0b00000010;
							break;}}
							break;
				} 
 
case 53	: {

						switch (state){
							case OFF: {
								U1_registers[2] = U1_registers[2] & 0b11101111;
							break;}
							case ON:{
								U1_registers[2] = U1_registers[2] | 0b00010000;
							break;}}
							break;
	}


	case 54	: {

						switch (state){
							case OFF: {
								U1_registers[2] = U1_registers[2] & 0b11111110;
							break;}
							case ON:{
								U1_registers[2] = U1_registers[2] | 0b00000001;
							break;}}
							break;
		}


		case 55	: {
		switch (state){
			case OFF: {
				U1_registers[1] = U1_registers[1] & 0b11101111;
			break;}
			case ON:{
				U1_registers[1] = U1_registers[1] | 0b00010000;
			break;}}
			break;
			}


			case 56	: {
	switch (state){
		case OFF: {
			U1_registers[1] = U1_registers[1] & 0b11111110;
		break;}
		case ON:{
			U1_registers[1] = U1_registers[1] | 0b00000001;
		break;}}
		break;
				} 
 
case 57	: {
	switch (state){
		case OFF: {
			U1_registers[0] = U1_registers[0] & 0b11110111;
		break;}
		case ON:{
			U1_registers[0] = U1_registers[0] | 0b00001000;
		break;}}
		break;
	}


	case 58	: {
		switch (state){
			case OFF: {
				U1_registers[0] = U1_registers[0] & 0b11101111;
			break;}
			case ON:{
				U1_registers[0] = U1_registers[0] | 0b00010000;
			break;}}
			break;
		}


		case 59	: {
			switch (state){
				case OFF: {
					U1_registers[0] = U1_registers[0] & 0b11011111;
				break;}
				case ON:{
					U1_registers[0] = U1_registers[0] | 0b00100000;
				break;}}
				break;
			}


			case 60	: {
				switch (state){
case OFF: {
	U1_registers[0] = U1_registers[0] & 0b10111111;
break;}
case ON:{
	U1_registers[0] = U1_registers[0] | 0b01000000;
					break;}}
					break;
				}
case 61	: {
	switch (state){
		case OFF: {
			U1_registers[5] = U1_registers[5] & 0b01111111;
		break;}
		case ON:{
			U1_registers[5] = U1_registers[5] | 0b10000000;
		break;}}
		break;
	}


	case 62	: {
		switch (state){
			case OFF: {
				U1_registers[0] = U1_registers[0] & 0b11111110;
			break;}
			case ON:{
				U1_registers[0] = U1_registers[0] | 0b00000001;
			break;}}
			break;
		}


		case 63	: {
			switch (state){
				case OFF: {
					U1_registers[0] = U1_registers[0] & 0b11111101;
				break;}
				case ON:{
					U1_registers[0] = U1_registers[0] | 0b00000010;
				break;}}
				break;
			}


			case 64	: {
				switch (state){
					case OFF: {
						U1_registers[0] = U1_registers[0] & 0b11111011;
					break;}
					case ON:{
						U1_registers[0] = U1_registers[0] | 0b00000100;
					break;}}
					break;
				}				
				
case 65	: {
	switch (state){
		case OFF: {
			U1_registers[4] = U1_registers[4] & 0b01111111;
		break;}
		case ON:{
			U1_registers[4] = U1_registers[4] | 0b10000000;
		break;}}
		break;
	}


	case 66	: {
		switch (state){
			case OFF: {
				U1_registers[4] = U1_registers[4] & 0b10111111;
			break;}
			case ON:{
				U1_registers[4] = U1_registers[4] | 0b01000000;
			break;}}
			break;
		}


		case 67	: {
			switch (state){
				case OFF: {
					U1_registers[4] = U1_registers[4] & 0b11011111;
				break;}
				case ON:{
					U1_registers[4] = U1_registers[4] | 0b00100000;
				break;}}
				break;
			}


			case 68	: {
				switch (state){
					case OFF: {
						U1_registers[4] = U1_registers[4] & 0b11101111;
					break;}
					case ON:{
						U1_registers[4] = U1_registers[4] | 0b00010000;
					break;}}
					break;
				}				

case 69	: {
	switch (state){
		case OFF: {
			U1_registers[3] = U1_registers[3] & 0b11111011;
		break;}
		case ON:{
			U1_registers[3] = U1_registers[3] | 0b00000100;
		break;}}
		break;
	}


	case 70	: {
		switch (state){
			case OFF: {
				U1_registers[3] = U1_registers[3] & 0b11011111;
			break;}
			case ON:{
				U1_registers[3] = U1_registers[3] | 0b00100000;
			break;}}
			break;
		}


		case 71	: {
			switch (state){
				case OFF: {
					U1_registers[4] = U1_registers[4] & 0b11111110;
				break;}
				case ON:{
					U1_registers[4] = U1_registers[4] | 0b00000001;
				break;}}
				break;
			}


			case 72	: {
				switch (state){
					case OFF: {
						U1_registers[4] = U1_registers[4] & 0b11110111;
					break;}
					case ON:{
						U1_registers[4] = U1_registers[4] | 0b00001000;
					break;}}
					break;
				}

case 73	: {
	switch (state){
		case OFF: {
			U1_registers[3] = U1_registers[3] & 0b11111101;
		break;}
		case ON:{
			U1_registers[3] = U1_registers[3] | 0b00000010;
		break;}}
		break;
	}


	case 74	: {
		switch (state){
			case OFF: {
				U1_registers[3] = U1_registers[3] & 0b11101111;
			break;}
			case ON:{
				U1_registers[3] = U1_registers[3] | 0b00010000;
			break;}}
			break;
		}


		case 75	: {
			switch (state){
				case OFF: {
					U1_registers[3] = U1_registers[3] & 0b01111111;
				break;}
				case ON:{
					U1_registers[3] = U1_registers[3] | 0b10000000;
				break;}}
				break;
			}


			case 76	: {
				switch (state){
					case OFF: {
						U1_registers[4] = U1_registers[4] & 0b11111011;
					break;}
					case ON:{
						U1_registers[4] = U1_registers[4] | 0b00000100;
					break;}}
					break;
				}
case 77	: {
	switch (state){
		case OFF: {
			U1_registers[3] = U1_registers[3] & 0b11111110;
		break;}
		case ON:{
			U1_registers[3] = U1_registers[3] | 0b00000001;
		break;}}
		break;
	}


	case 78	: {
		switch (state){
			case OFF: {
				U1_registers[3] = U1_registers[3] & 0b11110111;
			break;}
			case ON:{
				U1_registers[3] = U1_registers[3] | 0b00001000;
			break;}}
			break;
		}


		case 79	: {
			switch (state){
				case OFF: {
					U1_registers[3] = U1_registers[3] & 0b10111111;
				break;}
				case ON:{
					U1_registers[3] = U1_registers[3] | 0b01000000;
				break;}}
				break;
			}


			case 80	: {
				switch (state){
					case OFF: {
						U1_registers[4] = U1_registers[4] & 0b11111101;
					break;}
					case ON:{
						U1_registers[4] = U1_registers[4] | 0b00000010;
					break;}}
					break;
				}
				
default:
break;
}
}
																																										
