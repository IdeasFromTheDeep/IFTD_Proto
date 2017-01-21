// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

//RF: This makes the class accesible in blueprints
UCLASS(Blueprintable)
class IFTD_PROTO_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	//RF: UPROPERTY flags indicate specific behaviours in blueprints. Self explanatory
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Character")
		float health = 100;

	//RF: UPROPERTY flags indicate specific behaviours in blueprints. Self explanatory
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Base Character")
		bool isDead = false;

	//RF: Function declaration
	virtual void CalculateDead();

	//RF: Functions also have properties for blueprints
	//RF: The BlueprintCallable flag, turns this function into a Blueprint Node
	UFUNCTION(BlueprintCallable, Category = "Base Character")
		virtual void CalculateHealth(float delta);

	// RF: Override declaration of Property change event hook. ONLY fires is change is made in editor.
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& propertyChangedEvent) override;
#endif

	// Sets default values for this character's properties
	ABaseCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	
	
};
